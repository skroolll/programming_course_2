#include <iostream>
#include <cstdlib>  
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
// 3 ЗАДАНИЕ

    const int SIZE = 10;

// 1 СПОСОБ
    int arr1[SIZE];

    cout << "Статический массив + индексы: ";
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = i * i;
        cout << arr1[i] << " ";
    }
    cout << endl;

// 2 СПОСОБ
    int arr2[SIZE];

    int* ptr2 = arr2;

    cout << "Статический массив + указатели: ";
    for (int i = 0; i < SIZE; i++) {
        *ptr2 = i * i;  
        cout << *ptr2 << " ";
        ptr2++; 
    }
    ptr2 = arr2;
    cout << endl;

// 3 СПОСОБ
    int* arr3 = new int[SIZE];

    cout << "Динамический массив + индексы: ";
    for (int i = 0; i < SIZE; i++) {
        arr3[i] = i * i;
        cout << arr3[i] << " ";
    }
    delete[] arr3;
    cout << endl;

// 4 СПОСОБ
    int* arr4 = new int[SIZE];

    int* ptr4 = arr4;
    int* begin4 = arr4;

    cout << "Динамический массив + указатели: ";
    for (int i = 0; i < SIZE; i++) {
        *ptr4 = i * i;
        cout << *ptr4 << " ";
        ptr4++;
    }
    
    ptr4 = begin4;
    cout << endl;

    


// 3.2 ЗАДАНИЕ

    const int SIZE1 = 15;
    const int SIZE2 = 6;
    
    int* arr11 = new int[SIZE1];
    int* arr22 = new int[SIZE2];

    cout << "\nМассив A: ";
    for (int i = 0; i < SIZE1; i++) {
        arr11[i] = 1+rand() % 10;  
        cout << arr11[i] << " ";
    }
    cout << endl;

     cout << "Массив B: ";
    for (int i = 0; i < SIZE2; i++) {
        arr22[i] = 1+rand() % 10;  
        cout << arr22[i] << " ";
    }
    cout << endl;

    sort(arr11, arr11+SIZE1);
    sort(arr22, arr22+SIZE2);


    int size3 = SIZE1 + SIZE2;
    int* arr33 = new int[size3];

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < SIZE1 && j < SIZE2) {
        if (arr11[i] < arr22[j]) {
            arr33[k] = arr11[i];  
            i++;  
        } else {
            arr33[k] = arr22[j];  
            j++;  
        }
        k++; 
    }

    while (i < SIZE1) {
        arr33[k] = arr11[i];
        i++;
        k++;
    }

    while (j < SIZE2) {
        arr33[k] = arr22[j];
        j++;
        k++;
    }

    cout << "Результат слияния: ";
    for (int i = 0; i < size3; i++) {
        cout << arr33[i] << " ";
    }
    cout << endl;



// 4 ЗАДАНИЕ

    struct Node {
    int data;
    Node* prev;
    Node* next;
    int* number;
    };

    Node* tail = NULL; 
    Node* head = NULL; 

    
}