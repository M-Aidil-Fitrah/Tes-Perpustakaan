#include "header.h" // Sertakan header yang berisi definisi struct Book
#include <stdio.h>  // Sertakan header untuk fungsi-fungsi I/O
#include <stdbool.h> // Sertakan header untuk tipe data bool

void create_buku() {
    struct Book newBook = {0}; // Inisialisasi struct
    FILE *filePointer; // File pointer

    // Membuka file untuk ditulis
    filePointer = fopen("Berekstensi.txt", "a");
    if (filePointer == NULL) {
        printf("Error: Tidak dapat membuka atau membuat file Berekstensi.txt\n");
        return;
    }

    // Menulis header jika file masih kosong
    if (ftell(filePointer) == 0) {
        fprintf(filePointer, "| %-10s | %-40s | %-20s | %-20s | %-10s | %-14s | %-10s |\n",
                "ID BUKU", "JUDUL BUKU", "PENULIS", "PENERBIT", "HALAMAN", "TAHUN TERBIT", "JUMLAH BUKU YANG TERSEDIA");
        fprintf(filePointer, "|%-12s|%-42s|%-22s|%-22s|%-12s|%-16s|%-12s|\n",
                "-----------", "----------------------------------------", "--------------------",
                "--------------------", "-----------", "--------------", "--------------------------");
    }

    // Meminta masukan data buku dari pengguna
    printf("Masukkan detail buku:\n");
    printf("ID Buku: ");
    scanf("%u", &newBook.id_buku);
    printf("Judul Buku: ");
    scanf(" %[^\n]", newBook.judul_buku);
    printf("Penulis: ");
    scanf(" %[^\n]", newBook.penulis);
    printf("Penerbit: ");
    scanf(" %[^\n]", newBook.penerbit_buku);
    printf("Halaman: ");
    scanf("%u", &newBook.halaman);
    printf("Tahun Terbit: ");
    scanf("%u", &newBook.tahun_terbit);
    printf("Jumlah Buku Tersedia: ");
    scanf("%u", &newBook.jumlah_buku_tersedia);

    // Menulis data buku ke dalam file dalam format teks sebagai tabel
    fprintf(filePointer, "| %-10u | %-40s | %-20s | %-20s | %-10u | %-14u | %-10u |\n",
            newBook.id_buku, newBook.judul_buku, newBook.penulis, newBook.penerbit_buku,
            newBook.halaman, newBook.tahun_terbit, newBook.jumlah_buku_tersedia);

    // Menutup file setelah selesai menulis
    fclose(filePointer);

    printf("Buku berhasil ditambahkan!\n");
}