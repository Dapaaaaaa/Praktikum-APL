#include <iostream>
// Untuk agar bisa menggunakan command clear system
#include <cstdlib>

using namespace std;

// void sama seperti fungsi
void clearScreen() {
    system("cls");
}

// Program utama
int main() {
    int pin = 6050;
    int inputPin, saldo = 1000000, pilihan, jumlah;
    int kesempatan = 3;

clearScreen();

while (kesempatan > 0) {
    cout << "Masukan PIN Anda : ";
    cin >> inputPin;

    if (inputPin == pin) {
        break;

    } else {
        kesempatan--;
        cout << "PIN Anda Salah! Kesempatan Berkurang 1"<< endl;

        if (kesempatan == 0) {
            cout << "Kesempatan Habis, Program Berhenti" << endl;
            return 0;
        }
    }
}

do {
    clearScreen();
    cout << "\n=== MENU ===\n" << endl;
    cout << "1. Setor Tunai\n";
    cout << "2. Cek Saldo\n";
    cout << "3. Tarik Tunai\n";
    cout << "4. Keluar\n";
    cout << "Pilih Menu : ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            clearScreen();
            cout << "Masukan Jumlah Yang Ingin Disetor : ";
            cin >> jumlah;
            saldo += jumlah;
            cout << "Setor Tunai Berhasil!, Saldo anda saat ini : " << saldo << endl;
            cout << "Tekan Enter Untuk Melanjutkan" << endl;
            cin.ignore();
            cin.get();
            break;

        case 2:
            clearScreen();
            cout << "\nSaldo Anda : " << saldo << endl;
            cout << "Tekan Enter Untuk Melanjutkan" << endl;
            cin.ignore();
            cin.get();
            break;

        case 3:
            clearScreen();
            cout << "Masukan Jumlah Yang Ingin Ditarik : ";
            cin >> jumlah;
            if (jumlah > saldo) {
                cout << "Saldo Tidak Mencukupi" << endl;
            } else {
                saldo -= jumlah;
                cout << "Tarik Tunai Berhasil!, Saldo anda saat ini : " << saldo << endl;
            }
            cout << "Tekan Enter Untuk Melanjutkan" << endl;
            cin.ignore();
            cin.get();
            break;

        case 4:
            cout << "Program Berhenti" << endl;
            return 0;

        default:
            clearScreen();
            cout << "Pilihan Tidak Tersedia" << endl;
            cout << "Tekan Enter Untuk Melanjutkan" << endl;
            cin.ignore();
            cin.get();
            break;
}

} while (pilihan != 4);

return 0;
}
