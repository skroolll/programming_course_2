#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void demchar() {
    cout << "char" << endl;
    
    // длина
    char str1[] = "Hello";
    cout << "1. strlen(\"" << str1 << "\") = " << strlen(str1) << endl;

    // соединение
    strcat(str1, " World");
    cout << "3. strcat(str2, \" World\"): " << str1 << endl;
    
    // копирование
    char str2[20];
    strcpy(str2, str1);
    cout << "2. strcpy(str2, str1): str2 = " << str2 << endl;

}

int main() {
    demchar();
}