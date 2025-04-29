#include <iostream>

using namespace std;

void insertionSort(int a[], int panjang)
{
for (int i = 1; i < panjang; i++)
{
int key = a[i];
int j = i - 1;
while (j >= 0 && a[j] > key)

// Descending
while (j >= 0 && a[j] < key)

{
a[j + 1] = a[j];
j = j - 1;
}
a[j + 1] = key;
cout << "Tahap ke-" << i << ": ";
for (int k = 0; k < panjang; k++)
{
cout << a[k] << " ";
}
cout << endl;
}
}

int main()
{
int arr[10] = {44, 45, 43, 44, 41, 40, 42, 40, 45, 41};
int panjang = sizeof(arr) / sizeof(arr[0]);
insertionSort(arr, panjang);
return 0;
}