#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Cara penggunaan: ./program [admin/user]\n");
        return 1;
    }

    char *user_type = argv[1];

    if (strcmp(user_type, "admin") == 0) {
        printf("Selamat datang, Admin!\n");
        printf("Pilihan menu:\n");
        printf("1. Tambah Buku\n");
        printf("2. Update Buku\n");
        printf("3. Hapus Buku\n");
        int choice;
        printf("Pilih menu: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_buku();
                break;
            case 2:
                update_buku();
                break;
            case 3:
                delete_buku();
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    } else if (strcmp(user_type, "user") == 0) {
        printf("Selamat datang, User!\n");
        printf("Pilihan menu:\n");
        printf("1. Lihat Buku Tersedia\n");
        printf("2. Pinjam Buku\n");
        printf("3. Lihat Buku yang Dipinjam\n");
        printf("4. Kembalikan Buku\n");
        int choice;
        printf("Pilih menu: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_buku_tersedia();
                break;
            case 2:
                pinjam_buku();
                break;
            case 3:
                list_buku_dipinjam();
                break;
            case 4:
                kembalikan_buku();
                break;
            default:
                printf("Pilihan tidak valid\n");
                break;
        }
    } else {
        printf("Argumen tidak valid. Gunakan 'admin' atau 'user'.\n");
        return 1;
    }

    return 0;
}
