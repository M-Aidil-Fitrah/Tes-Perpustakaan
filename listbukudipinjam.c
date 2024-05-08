#include <stdio.h>
#include "header.h"

void list_buku_dipinjam() {
    FILE *filePointer;
    filePointer = fopen("Berekstensi.txt", "r");
    if (filePointer == NULL) {
        printf("Error: Tidak dapat membuka file Berekstensi.txt\n");
        return;
    }

    printf("Daftar Buku yang Sedang Dipinjam:\n");
    printf("| %-7s | %-40s | %-20s | %-15s | %-14s | %-12s | %-26s |\n", "ID BUKU", "JUDUL BUKU", "PENULIS", "PENERBIT", "JUMLAH HALAMAN", "TAHUN TERBIT", "JUMLAH BUKU YANG TERSEDIA");
    printf("|%-9s|%-42s|%-22s|%-17s|%-16s|%-14s|%-28s|\n", "---------", "----------------------------------------", "--------------------", "---------------", "----------------", "--------------", "--------------------------");

    char line[200];
    while (fgets(line, sizeof(line), filePointer)) {
        struct Book book;
        sscanf(line, "%u|%[^|]|%[^|]|%[^|]|%u|%u|%u", &book.id_buku, book.judul_buku, book.penulis, book.penerbit_buku,
                &book.halaman, &book.tahun_terbit, &book.jumlah_buku_tersedia);
        if (book.jumlah_buku_tersedia < 100) { // Misalnya, Anda menandai buku yang dipinjam dengan jumlah yang kurang dari 100
            printf("| %-7u | %-40s | %-20s | %-15s | %-14u | %-12u | %-26u |\n", book.id_buku, book.judul_buku, book.penulis, book.penerbit_buku,
                    book.halaman, book.tahun_terbit, book.jumlah_buku_tersedia);
        }
    }

    fclose(filePointer);
}
