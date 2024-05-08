#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

void pinjam_buku() {
    unsigned int id_to_borrow;
    printf("Masukkan ID Buku yang ingin dipinjam: ");
    scanf("%u", &id_to_borrow);

    // Membaca file dan menyalin data ke file sementara dengan mengurangi jumlah buku yang tersedia
    FILE *filePointer;
    filePointer = fopen("Berekstensi.txt", "r");
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

        if (book.id_buku == id_to_borrow) {
            if (book.jumlah_buku_tersedia > 0) {
                book.jumlah_buku_tersedia--;
                printf("Buku dengan ID %u berhasil dipinjam:\n", id_to_borrow);
                found = true;
            } else {
                printf("Buku dengan ID %u tidak tersedia untuk dipinjam\n", id_to_borrow);
            }
        }
        fprintf(tempPointer, "%u|%s|%s|%s|%u|%u|%u", book.id_buku, book.judul_buku, book.penulis, book.penerbit_buku,
                book.halaman, book.tahun_terbit, book.jumlah_buku_tersedia);
    }

    fclose(filePointer);
    fclose(tempPointer);

    // Mengganti file asli dengan file sementara
    remove("Berekstensi.txt");
    rename(tempFile, "Berekstensi.txt");

    if (!found) {
        printf("Buku dengan ID %u tidak ditemukan\n", id_to_borrow);
    }
}
