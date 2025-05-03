#include "Class.h"

int main() {
    // Membuat objek dosen
    Dosen dosenAlprog("Mr. Budi", 10);
    Dosen dosenSisben("Mr. Thomas", 11);
    Dosen dosenMatdis("Ms. Puff", 12);
    Dosen dosenFislis("Ms. Sandy", 13);

    // Membuat objek kelas
    Kelas alprog("Algoritma Pemrograman", 3.7, 3, dosenAlprog);
    Kelas sisben("Sistem Benam", 3.8, 3, dosenSisben);
    Kelas matdis("Matematika Diskrit", 3.5, 3, dosenMatdis);
    Kelas fislis("Fisika Listrik", 3.9, 2, dosenFislis);

    // Membuat objek mahasiswa
    Mahasiswa mhs("Hasan", 202210, alprog, sisben, matdis, fislis, ELEKTRO);

    // Menampilkan detail mahasiswa
    mhs.showDetail();

    return 0;
}
