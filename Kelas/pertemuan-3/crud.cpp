#include <iostream>
using namespace std;

struct Alamat{
    string jalan;
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

#define MAX_MAHASISWA 5

int main()
{
    int panjang = 0;
    Mahasiswa mhs[MAX_MAHASISWA];
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
                cout << "Belum ada data bos" << endl;
            else {
                cout << "Data Mahasiswa : " << endl;
                for (int i = 0; i < panjang; i++) {
                    cout << "Nama\t : " << mhs[i].nama << endl;
                    cout << "NIM\t : " << mhs[i].nim << endl;
                    cout << "Prodi\t : " << mhs[i].ipk << endl;
                    cout << "IPK\t : " << mhs[i].prodi << endl;
                    cout << "Angkatan : " << mhs[i].angkatan << endl;
                    cout << "Alamat\t : " << mhs[i].alamat.jalan << endl;
                    cout << "Kota\t : " << mhs[i].alamat.kota << endl;
                }
            }

            break;
        case 2:

            if (panjang < MAX_MAHASISWA) {
                cout << "Masukkan nama : ";
                cin.ignore();
                getline(cin, mhs[panjang].nama);
                // cout << "Masukkan NIM : ";
                // cin.ignore();
                // getline(cin, mhs[panjang].nim);
                // cout << "Masukkan Prodi : ";
                // getline(cin, mhs[panjang].prodi);
                // cout << "Masukkan IPK : ";
                // cin >> mhs[panjang].ipk;
                // cout << "Masukkan Angkatan : ";
                // cin >> mhs[panjang].angkatan;
                // cout << "Masukkan Alamat : ";
                // cin.ignore();
                // getline(cin, mhs[panjang].alamat.jalan);
                // cout << "Masukkan Kota : ";
                // getline(cin, mhs[panjang].alamat.kota);
                panjang++;
            } else {
                cout << "Penuh bang" << endl;
            }
            break;

        case 3:
            break;

        case 4:
        cout << "Daftar Mahasiswa" << endl;
            for(int i = 0; i < panjang; i++){
                cout << i+1 << "Nama:\t" << mhs[i].nama << endl;
            }

            int index;

            cout << "Masukan nomor mahasiswa yang ingin dihapus" << endl;
            cin >> index;

            for(int i = index-1; i < panjang-1; i++){
                mhs[i] = mhs[i+1];
            }

            panjang--;
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