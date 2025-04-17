// #include <iostream>

// using namespace std;

// int ubahNilai(int &a, int b){
//     return a = b;
//     }

// int main() {
//         int a,b;
//         a = 5;
//         b = 20;
//         ubahNilai(a, b);
//         cout << a << endl;

//     // int ubahNilai (int a, int b){
//     //     return a, b;
//     // }

//     // int a = 10;
//     // int b = 20;
//     // cout << "alamat a: " << &a << endl;
//     // cout << "alamat b: " << &b << endl;
//     // cout << "nilai a: " << a << endl;
//     // cout << "nilai b: " << b << endl;
       
// // int a = 10;
// // int b = 20;

// // b = 30;

// // cout << "Nilai a: " << a << endl;
// // cout << "Nilai b: " << b << endl;

// // return 0;

// // struct Address{
// //     string kota;
// //     string provinsi;
// //     string negara;
// //     };
// //     // deklarasi variabel dengan struct
// //     Address address1;
// //     // mengisi value address1
// //     address1.kota = "Samarinda";
// //     address1.provinsi = "Kalimantan Timur";
// //     address1.negara = "Indonesia";
// //     // mengcopy value address1 ke address2

// //     Address *address2 = &address1;

// //     address2->kota = "Samarinda";

// //     // address2 = address1;
// //     // mengganti property kota dari samarinda ke ikn
// //     // address2.kota = "ikn";
// //     // value address1
// //     cout<< &address1.kota <<endl;
// //     // value address2
// //     // cout<< &address2.kota <<endl;

// //     string *b = &address1.kota;
// //     cout << b << endl;
// //     cout << &b << endl;
// //     cout << *b << endl;

// int arr[3] = {1,2,3};

// cout << arr << endl;

// }

#include <iostream>
using namespace std;

struct Alamat
{
    string jalan;
    string kota;
};

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
    Alamat alamat;
};

Mahasiswa *mhsPtr = mhs;

// for (int i = 0; i < MAX_MAHASISWA; i++);

#define MAX_MAHASISWA 5
int panjang = 0;
Mahasiswa mhs[MAX_MAHASISWA];

void tampilkanData()
{
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << (i + 1) << ".\t" << "Nama\t: " << mhs[i].nama << endl;
        cout << "\tNIM\t: " << mhs[i].nim << endl;
        cout << "\tIPK\t: " << mhs[i].ipk << endl;
        cout << "\tJalan\t: " << mhs[i].alamat.jalan << endl;
        cout << "\tKota\t: " << mhs[i].alamat.kota << endl
             << endl;
    }
}

void tambahkanData()
{
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, mhs[panjang].nama);

    cout << "Masukkan NIM: ";
    cin.ignore();
    getline(cin, mhs[panjang].nim);

    cout << "Masukkan ipk: ";
    cin >> mhs[panjang].ipk;

    cout << "Masukkan jalan: ";
    cin.ignore();
    getline(cin, mhs[panjang].alamat.jalan);

    cout << "Masukkan kota: ";
    // cin.ignore();
    getline(cin, mhs[panjang].alamat.kota);

    panjang++;
    cout << "Mahasiswa berhasil ditambahkan" << endl;
}

void ubahData()
{
    int index;
    cout << "Masukkan nomor mahasiswa yang ingin diubah: ";
    cin >> index;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, mhs[index - 1].nama);

    cout << "Masukkan NIM: ";
    cin.ignore();
    getline(cin, mhs[index - 1].nim);

    cout << "Masukkan ipk: ";
    cin >> mhs[index - 1].ipk;

    cout << "Masukkan jalan: ";
    cin.ignore();
    getline(cin, mhs[index - 1].alamat.jalan);

    cout << "Masukkan kota: ";
    // cin.ignore();
    getline(cin, mhs[index - 1].alamat.kota);
}

void hapusData()
{
    int index;
    cout << "Masukkan nomor mahasiswa yang ingin dihapus: ";
    cin >> index;

    for (int i = index - 1; i < panjang - 1; i++)
    {
        mhs[i] = mhs[i + 1];
    }
    panjang--;
}

int main()
{
    int pilihan;

    do
    {
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (panjang == 0)
                cout << "Belum ada datang bang" << endl;
            else
            {
                tampilkanData();
            }
            break;
        case 2:
            if (panjang < MAX_MAHASISWA)
            {
                tambahkanData();
            }
            else
            {
                cout << "Penuh sudah bang" << endl;
            }
            break;
        case 3:
            if (panjang == 0)
            {
                cout << "Belum ada datang bang" << endl;
            }
            else
            {
                tampilkanData();
                ubahData();
            }
            break;
        case 4:
            if (panjang == 0)
                cout << "Belum ada datang bang" << endl;
            else
            {
                tampilkanData();
                hapusData();
            }
            break;

        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);
}