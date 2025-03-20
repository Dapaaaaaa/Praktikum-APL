#include <iostream>

using namespace std;

struct Alamat{
    string jalan;
    int nomor;
    string kota;
};

struct Mahasiswa
{
    string nama;
    string nim;
    string prodi;
    float ipk;
    int angkatan;
    Alamat alamat;
};

int main ()
{

    Mahasiswa mhs[5];

    Mahasiswa mhs1;

    mhs[0].nama = "Daffa";
    mhs[0].nim = "2409106050";
    mhs[0].prodi = "Informatika";
    mhs[0].ipk = 4.0;
    mhs[0].angkatan = 2019;
    mhs[0].alamat.jalan = "Jl. Suwandi";
    mhs[0].alamat.nomor = 1;
    mhs[0].alamat.kota = "Samarinda";



    // mhs1 = mhs2;

    // Mahasiswa mhs2;
    // mhs2.nama = "Dimas";
    // mhs2.nim = "2409106051";
    // mhs2.prodi = "Informatika";
    // mhs2.ipk = 4.0;
    // mhs2.angkatan = 2023;

    cout << "Nama\t\t:" << mhs[0].nama << endl;
    cout << "NIM\t\t:" << mhs[0].nim << endl;
    cout << "Prodi\t\t:" << mhs[0].prodi << endl;
    cout << "IPK\t\t:" << mhs[0].ipk << endl;
    cout << "Angkatan\t:" << mhs[0].angkatan << endl;
    

    return 0;
}
