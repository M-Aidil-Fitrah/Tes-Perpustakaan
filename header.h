#ifndef HEADER_H
#define HEADER_H

struct Book {
    unsigned int id_buku;
    char judul_buku[100];
    char penulis[100];
    char penerbit_buku[100];
    unsigned int halaman;
    unsigned int tahun_terbit;
    unsigned int jumlah_buku_tersedia;
};

void create_buku();
void update_buku();
void delete_buku();
void list_buku_tersedia();
void pinjam_buku();
void list_buku_dipinjam();
void kembalikan_buku();

#endif
