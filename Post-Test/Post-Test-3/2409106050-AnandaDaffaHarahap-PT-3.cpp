#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_RUANGAN = 10;

const int MAX_PENGGUNA = 2;

struct pengguna
{
    string nama;
    string nim;
    string status;
};

pengguna daftarPengguna[MAX_PENGGUNA] = {
    {"Daffa", "2409106050", "Admin"},
    {"daffa", "2409106050", "Kasir"},
};

struct fasilitas
{
    string meja;
    bool proyektor;
    bool whiteboard;
    bool soundSystem;
    bool ac;
    bool wifi;
};

struct Ruangan {
    string nama;
    bool tersedia;
    int harga;
    int kapasitas;
    fasilitas fasilitas;
    int durasi;
};

Ruangan daftarRuangan[MAX_RUANGAN] = {
    {"Ruang A", true, 25000, 4, {"Meja biasa", true, false, false, false, true}, 0},
    {"Ruang B", true, 30000, 4, {"Meja biasa", true, false, false, true, true}, 0},
    {"Ruang C", true, 35000, 6, {"Meja diskusi", false, true, false, true, true}, 0},
    {"Ruang D", true, 40000, 8, {"Meja Rapat", true, false, true, false, true}, 0},
    {"Ruang E", true, 50000, 10, {"Meja Rapat", true, true, true, false, true}, 0}
};

int jumlahRuangan = 5;

int main() {
    string nama, nim, status;
    int kesempatan = 3;
    bool loginBerhasil = false;
    bool isAdmin = false;
    
    while (kesempatan--) {
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        
        if (nama == daftarPengguna[0].nama && nim == daftarPengguna[0].nim) {
            loginBerhasil = true;
            isAdmin = (daftarPengguna[0].status == "Admin");
            break;
        } else if (nama == daftarPengguna[1].nama && nim == daftarPengguna[1].nim) {
            loginBerhasil = true;
            isAdmin = (daftarPengguna[1].status == "Admin");
            break;
        }
        cout << "Login gagal! Kesempatan tersisa: " << kesempatan << endl;
    }
    
    if (!loginBerhasil) {
        cout << "Anda telah gagal login 3 kali. Program berhenti." << endl;
        return 0;
    }
    
    int pilihan;
    do {
        if (isAdmin) {
            cout << "\nMenu Admin:\n";
            cout << "1. Tambah Ruangan\n";
            cout << "2. Lihat Ruangan\n";
            cout << "3. Perbarui Ruangan\n";
            cout << "4. Hapus Ruangan\n";
            cout << "5. Keluar\n";
        } else {
            cout << "\nMenu Kasir:\n";
            cout << "1. Lihat Ruangan\n";
            cout << "2. Pesan Ruangan\n";
            cout << "3. Konfirmasi Pembayaran\n";
            cout << "4. Keluar\n";
        }
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();
        
        if (isAdmin) {
            if (pilihan == 1) {

                cout << "\nDaftar Ruangan:\n";
                cout << "--------------------------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(15) << "Status"
                     << setw(10) << "Harga" << setw(10) << "Kapasitas" << setw(10) << "Durasi"
                     << "Fasilitas" << endl;
                for (int i = 0; i < jumlahRuangan; i++) {
                    cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                         << setw(15) << (daftarRuangan[i].tersedia ? "Tersedia" : "Dipesan")
                         << setw(10) << daftarRuangan[i].harga
                         << setw(10) << daftarRuangan[i].kapasitas
                         << setw(10) << (daftarRuangan[i].durasi > 0 ? to_string(daftarRuangan[i].durasi) + " jam" : "-")
                         << daftarRuangan[i].fasilitas.meja << ", "
                         << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                         << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                         << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                         << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                         << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                }
                cout << "--------------------------------------------------------------------\n";

                if (jumlahRuangan < MAX_RUANGAN) {
                    cout << "Masukkan nama ruangan : ";
                    getline(cin, daftarRuangan[jumlahRuangan].nama);
                    cout << "Masukkan harga : ";
                    cin >> daftarRuangan[jumlahRuangan].harga;
                    cout << "Masukkan kapasitas ruangan : ";
                    cin >> daftarRuangan[jumlahRuangan].kapasitas;
                    cin.ignore();

                    cout << "Masukkan Meja : ";
                    getline(cin, daftarRuangan[jumlahRuangan].fasilitas.meja);

                    char pilihan;
                    cout << "Apakah ada proyektor? (y/n) : ";
                    cin >> pilihan;
                    daftarRuangan[jumlahRuangan].fasilitas.proyektor = (pilihan == 'y');

                    cout << "Apakah ada whiteboard? (y/n) : ";
                    cin >> pilihan;
                    daftarRuangan[jumlahRuangan].fasilitas.whiteboard = (pilihan == 'y');

                    cout << "Apakah ada sound system? (y/n) : ";
                    cin >> pilihan;
                    daftarRuangan[jumlahRuangan].fasilitas.soundSystem = (pilihan == 'y');

                    cout << "Apakah ada AC? (y/n) : ";
                    cin >> pilihan;
                    daftarRuangan[jumlahRuangan].fasilitas.ac = (pilihan == 'y');

                    cout << "Apakah ada wifi? (y/n) : ";
                    cin >> pilihan;
                    daftarRuangan[jumlahRuangan].fasilitas.wifi = (pilihan == 'y');
                    daftarRuangan[jumlahRuangan].durasi = 0;
                    daftarRuangan[jumlahRuangan].tersedia = true;
                    jumlahRuangan++;

                    cout << "Ruangan berhasil ditambahkan!\n";
                } else {
                    cout << "Kapasitas ruangan penuh!\n";
                }

            } 
            
            else if (pilihan == 2) {
                cout << "\nDaftar Ruangan:\n";
                cout << "--------------------------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(15) << "Status"
                     << setw(10) << "Harga" << setw(10) << "Kapasitas" << setw(10) << "Durasi"
                     << "Fasilitas" << endl;
                for (int i = 0; i < jumlahRuangan; i++) {
                    cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                         << setw(15) << (daftarRuangan[i].tersedia ? "Tersedia" : "Dipesan")
                         << setw(10) << daftarRuangan[i].harga
                         << setw(10) << daftarRuangan[i].kapasitas
                         << setw(10) << (daftarRuangan[i].durasi > 0 ? to_string(daftarRuangan[i].durasi) + " jam" : "-")
                         << daftarRuangan[i].fasilitas.meja << ", "
                         << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                         << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                         << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                         << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                         << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                }
                cout << "--------------------------------------------------------------------\n";
            }

            else if (pilihan == 3) {
                cout << "\nDaftar Ruangan:\n";
                cout << "--------------------------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(15) << "Status"
                     << setw(10) << "Harga" << setw(10) << "Kapasitas" << setw(10) << "Durasi"
                     << "Fasilitas" << endl;
                for (int i = 0; i < jumlahRuangan; i++) {
                    cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                         << setw(15) << (daftarRuangan[i].tersedia ? "Tersedia" : "Dipesan")
                         << setw(10) << daftarRuangan[i].harga
                         << setw(10) << daftarRuangan[i].kapasitas
                         << setw(10) << (daftarRuangan[i].durasi > 0 ? to_string(daftarRuangan[i].durasi) + " jam" : "-")
                         << daftarRuangan[i].fasilitas.meja << ", "
                         << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                         << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                         << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                         << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                         << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                }
                cout << "--------------------------------------------------------------------\n";
                
                cout << "Masukkan nomor ruangan yang ingin diperbarui : ";
                int pilih;
                cin >> pilih;
                cin.ignore();
                if (pilih >= 1 && pilih <= jumlahRuangan) {
                    cout << "Masukkan nama : ";
                    getline(cin, daftarRuangan[pilih - 1].nama);

                    cout << "Masukkan harga : ";
                    cin >> daftarRuangan[pilih - 1].harga;
                    cout << "Masukkan kapasitas : ";
                    cin >> daftarRuangan[pilih - 1].kapasitas;
                    cin.ignore();

                    cout << "Masukkan jenis meja: ";
                    getline(cin, daftarRuangan[pilih - 1].fasilitas.meja);

                    char pilihan;
                    cout << "Apakah ada proyektor? (y/n): ";
                    cin >> pilihan;
                    daftarRuangan[pilih - 1].fasilitas.proyektor = (pilihan == 'y');

                    cout << "Apakah ada whiteboard? (y/n): ";
                    cin >> pilihan;
                    daftarRuangan[pilih - 1].fasilitas.whiteboard = (pilihan == 'y');

                    cout << "Apakah ada sound system? (y/n): ";
                    cin >> pilihan;
                    daftarRuangan[pilih - 1].fasilitas.soundSystem = (pilihan == 'y');

                    cout << "Apakah ada AC? (y/n): ";
                    cin >> pilihan;
                    daftarRuangan[pilih - 1].fasilitas.ac = (pilihan == 'y');

                    cout << "Apakah ada WiFi? (y/n): ";
                    cin >> pilihan;
                    daftarRuangan[pilih - 1].fasilitas.wifi = (pilihan == 'y');

                    cin.ignore();
                    cout << "Ruangan berhasil diperbarui!\n";
                } else {
                    cout << "Nomor ruangan tidak valid!\n";
                }
            } 

            else if (pilihan == 4) {

                cout << "\nDaftar Ruangan:\n";
                cout << "--------------------------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(15) << "Status"
                     << setw(10) << "Harga" << setw(10) << "Kapasitas" << setw(10) << "Durasi"
                     << "Fasilitas" << endl;
                for (int i = 0; i < jumlahRuangan; i++) {
                    cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                         << setw(15) << (daftarRuangan[i].tersedia ? "Tersedia" : "Dipesan")
                         << setw(10) << daftarRuangan[i].harga
                         << setw(10) << daftarRuangan[i].kapasitas
                         << setw(10) << (daftarRuangan[i].durasi > 0 ? to_string(daftarRuangan[i].durasi) + " jam" : "-")
                         << daftarRuangan[i].fasilitas.meja << ", "
                         << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                         << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                         << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                         << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                         << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                }
                cout << "--------------------------------------------------------------------\n";

                cout << "Masukkan nomor ruangan yang ingin dihapus : ";
                int pilih;
                cin >> pilih;
                if (pilih >= 1 && pilih <= jumlahRuangan) {
                    for (int i = pilih - 1; i < jumlahRuangan - 1; i++) {
                        daftarRuangan[i] = daftarRuangan[i + 1];
                    }
                    jumlahRuangan--;
                    cout << "Ruangan berhasil dihapus!\n";
                } else {
                    cout << "Nomor ruangan tidak valid!\n";
                }
            }
        } else {

            if (pilihan == 1) {
                cout << "\nDaftar Ruangan:\n";
                cout << "--------------------------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(15) << "Status"
                     << setw(10) << "Harga" << setw(10) << "Kapasitas" << setw(10) << "Durasi"
                     << "Fasilitas" << endl;
                for (int i = 0; i < jumlahRuangan; i++) {
                    cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                         << setw(15) << (daftarRuangan[i].tersedia ? "Tersedia" : "Dipesan")
                         << setw(10) << daftarRuangan[i].harga
                         << setw(10) << daftarRuangan[i].kapasitas
                         << setw(10) << (daftarRuangan[i].durasi > 0 ? to_string(daftarRuangan[i].durasi) + " jam" : "-")
                         << daftarRuangan[i].fasilitas.meja << ", "
                         << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                         << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                         << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                         << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                         << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                }
                cout << "--------------------------------------------------------------------\n";

            } 
            
            else if (pilihan == 2) {

                cout << "\nDaftar Ruangan :\n";
                cout << "--------------------------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(15) << "Status"
                     << setw(10) << "Harga" << setw(10) << "Kapasitas" << setw(10) << "Durasi"
                     << "Fasilitas" << endl;
                for (int i = 0; i < jumlahRuangan; i++) {
                    cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                         << setw(15) << (daftarRuangan[i].tersedia ? "Tersedia" : "Dipesan")
                         << setw(10) << daftarRuangan[i].harga
                         << setw(10) << daftarRuangan[i].kapasitas
                         << setw(10) << (daftarRuangan[i].durasi > 0 ? to_string(daftarRuangan[i].durasi) + " jam" : "-")
                         << daftarRuangan[i].fasilitas.meja << ", "
                         << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                         << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                         << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                         << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                         << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                }
                cout << "--------------------------------------------------------------------\n";

                cout << "Masukkan nomor ruangan yang ingin dipesan : ";
                int pilih, durasi;
                cin >> pilih;
                cout << "Masukkan durasi : ";
                cin >> durasi;
                if (pilih >= 1 && pilih <= jumlahRuangan && daftarRuangan[pilih - 1].tersedia) {
                    daftarRuangan[pilih - 1].tersedia = false;
                    daftarRuangan[pilih - 1].durasi = durasi;
                    cout << "Ruangan " << daftarRuangan[pilih - 1].nama << " berhasil dipesan.\n";
                } else {
                    cout << "Ruangan tidak tersedia atau nomor salah!\n";
                }
            }

            else if (pilihan == 3) {
                cout << "\nDaftar Ruangan yang Dipesan :\n";
                cout << "-----------------------------------------------------\n";
                cout << left << setw(10) << "No" << setw(15) << "Nama" << setw(10) << "Harga" 
                     << setw(10) << "Kapasitas" << setw(10) << "Durasi" << "Fasilitas" << endl;
            
                int count = 0;
                for (int i = 0; i < jumlahRuangan; i++) {
                    if (!daftarRuangan[i].tersedia) {
                        cout << left << setw(10) << (i + 1) << setw(15) << daftarRuangan[i].nama
                             << setw(10) << daftarRuangan[i].harga
                             << setw(10) << daftarRuangan[i].kapasitas
                             << setw(10) << daftarRuangan[i].durasi
                             << daftarRuangan[i].fasilitas.meja << ", "
                             << (daftarRuangan[i].fasilitas.proyektor ? "Proyektor, " : "")
                             << (daftarRuangan[i].fasilitas.whiteboard ? "Whiteboard, " : "")
                             << (daftarRuangan[i].fasilitas.soundSystem ? "Sound System, " : "")
                             << (daftarRuangan[i].fasilitas.ac ? "AC, " : "")
                             << (daftarRuangan[i].fasilitas.wifi ? "Wifi" : "") << endl;
                        count++;
                    }
                }
            
                if (count == 0) {
                    cout << "Tidak ada ruangan yang dipesan.\n";
                } else {
                    cout << "-----------------------------------------------------\n";
                    cout << "Masukkan nomor ruangan yang ingin dikonfirmasi pembayarannya : ";
                    int pilih;
                    cin >> pilih;
            
                    if (pilih >= 1 && pilih <= jumlahRuangan && !daftarRuangan[pilih - 1].tersedia) {
                        daftarRuangan[pilih - 1].tersedia = true;
                        daftarRuangan[pilih - 1].durasi = 0;
                        cout << "Pembayaran untuk ruangan " << daftarRuangan[pilih - 1].nama << " dikonfirmasi.\n";
                        cout << "Ruangan kini tersedia kembali.\n";
                    } else {
                        cout << "Nomor ruangan tidak valid atau belum dipesan!\n";
                    }
                }
            }            
            }
    } while ((isAdmin && pilihan != 5) || (!isAdmin && pilihan != 4));
    
    cout << "Terima kasih telah menggunakan layanan kami!\n";
    return 0;
}
