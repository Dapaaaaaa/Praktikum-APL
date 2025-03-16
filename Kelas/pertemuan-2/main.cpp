#include <iostream>

using namespace std;

int main() {
    // string nama[5] = {"daffa", "dimas", "santoso", "stepan", "harahap"};

    // int angka [3];

    // angka[0] = 1;
    // angka[1] = 2;
    // angka[2] = 3;

    // double angka[5] ={1, 2, 3, 4, 5};

    // angka [1] = 6;

    // return 0; 

//     cout << nama[4] << endl;

//     // cout << angka[0] << endl;

//     cout << sizeof(angka) << endl;

//     int panjang1 = sizeof(angka) / sizeof(angka[0]);
//     int panjang2 = sizeof(angka) / sizeof(int);

//     cout << panjang1 << endl;
//     cout << panjang2 << endl;

//     cout << sizeof(double) << endl;

//     // Kalau gini muncul nya memory karena buffer
//     cout << angka << endl;

//     for (int i = 0; i < panjang1; i++ ) {
//         cout << angka[i] << endl;
//     }

//     for (int item : angka) {
//         cout << item << endl;
//         }

//    for (int i = 0; i < panjang1; i++) {
//     cout << angka[i] << endl;
//    }     

// int matriks[2][2] = {
//     {1, 2},
//     {3, 4}
//     };
    
//     cout << matriks[0][0] << endl;

int angka[2][3][2] = {
    {
        {1,2},
        {3,4},
        {5,6}
    },
    {
        {7,8},
        {9,10},
        {11,12},
    },
    };

    cout << angka[1][1][1] << endl;

return 0;

}