#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

void update_buku() {
    unsigned int id_to_update;
    printf("Masukkan ID Buku yang ingin diperbarui: ");
    scanf("%u", &id_to_update);

    // Membaca file dan mencari buku dengan ID yang sesuai
    FILE *filePointer;
    filePointer = fopen("Berekstensi.txt", "r+");
    if (filePointer == NULL) {
        printf("Error: Tidak dapat membuka file Berekstensi.txt\n");
        return;
    }

    char line[200];
    char tempFile[] = "temp.txt";
    FILE *tempPointer = fopen(tempFile, "w");
    if (tempPointer == NULL) {
        printf("Error: Tidak dapat membuat file sementara\n");
        fclose(filePointer);
        return;
    }

    bool found = false;
    while (fgets(line, sizeof(line), filePointer)) {
        struct Book book;
        sscanf(line, "%u|%[^|]|%[^|]|%[^|]|%u|%u|%u", &book.id_buku, book.judul_buku, book.penulis, book.penerbit_buku,
                &book.halaman, &book.tahun_terbit, &book.jumlah_buku_tersedia);

        if (book.id_buku == id_to_update) {
            printf("Masukkan detail baru untuk buku dengan ID %u:\n", id_to_update);
            printf("Judul Buku     : ");
            getchar(); // Membersihkan \n di input sebelumnya
            fgets(book.judul_buku, sizeof(book.judul_buku), stdin);
            printf("Penulis        : ");
            fgets(book.penulis, sizeof(book.penulis), stdin);
            printf("Penerbit       : ");
            fgets(book.penerbit_buku, sizeof(book.penerbit_buku), stdin);
            printf("Jumlah Halaman : ");
            scanf("%u", &book.halaman);
            printf("Tahun Terbit   : ");
            scanf("%u", &book.tahun_terbit);
            printf("Jumlah Tersedia: ");
            scanf("%u", &book.jumlah_buku_tersedia);

            // Mengganti data buku yang lama dengan yang baru di file sementara
            fprintf(tempPointer, "%u|%s|%s|%s|%u|%u|%u\n", book.id_buku, book.judul_buku, book.penulis, book.penerbit_buku,
                    book.halaman, book.tahun_terbit, book.jumlah_buku_tersedia);
            printf("Buku berhasil diperbarui!\n");
            found = true;
        } else {
            // Menyalin data buku yang tidak diperbarui ke file sementara
            fprintf(tempPointer, "%u|%s|%s|%s|%u|%u|%u", book.id_buku, book.judul_buku, book.penulis, book.penerbit_buku,
                    book.halaman, book.tahun_terbit, book.jumlah_buku_tersedia);
        }
    }

    fclose(filePointer);
    fclose(tempPointer);

    // Mengganti file asli dengan file sementara
    remove("Berekstensi.txt");
    rename(tempFile, "Berekstensi.txt");

    if (!found) {
        printf("Buku dengan ID %u tidak ditemukan\n", id_to_update);
    }
}
