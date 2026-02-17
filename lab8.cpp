#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;

    cout << "\nСтатический массив + индексы" << endl;
    int arr1[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr1[i] = i * i;  
    }

    cout << "Результат: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    



    cout << "\nСтатический массив + указатели" << endl;
    int arr2[SIZE];

    int* ptr2 = arr2;

    cout << "Результат: ";
    for (int i = 0; i < SIZE; i++) {
        *ptr2 = i * i;  
        cout << *ptr2 << " ";
        ptr2++; 
    }
    ptr2 = arr2;
    cout << endl;




    cout << "\nДинамический массив + индексы" << endl;
    int* arr3 = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        arr3[i] = i * i;
    }

    cout << "Результат: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;

    delete[] arr3;
}