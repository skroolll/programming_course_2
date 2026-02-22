#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void demchar() {
    cout << "char" << endl;
    
    // длина
    char str1[] = "hello";
    cout << "1. strlen: " << strlen(str1) << endl;
    
    // копирование
    char str2[20];
    strcpy(str2, str1);
    cout << "2. strcpy: " << str2 << endl;

    // соединение
    strcat(str2, " world");
    cout << "3. strcat: " << str2 << endl;

}


void demstring() {
    cout << "\nstring" << endl;

    //длина
    string s1 = "hello";
    cout << "1. lenght: " << s1.length() << endl;

    //добавление
    s1.append(" world");
    cout << "2. append: " << s1 << endl;

    //извлечение
    string s2 = s1.substr(0,5);
    cout << "3. substr: " << s2 << endl;

}


void zadanie_na_massiv() {
    const int max_words = 20;
    const int max_words_len = 10;

    //вариант С строк
    char cWords[max_words][max_words_len + 1];
    int n;

    cout << "\n(С)введите кол-во слов от 1 до " << max_words << ": ";
    cin >> n;

    while (0>=n || n>=21) {
        cout << "ошибка, введите число от 1 до 20: ";
        cin >> n;
    }
    cin.get();

    cout << "Введите слова: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "  Слово " << i + 1 << ": ";
        cin.getline(cWords[i], max_words_len + 1); 
    } 

    cout << "cлова с четными номерами: ";
    for (int i = 1; i < n; i += 2) {
        cout << cWords[i] << " ";
    }
    cout << endl;


    //вариант С++ строк   
    string sWords[max_words]; 
    int m = 0;
    
    cout << "\n(С++)введите кол-во слов от 1 до " << max_words << ": ";
    cin >> m;

    while (0>=m || m>=21) {
        cout << "ошибка, введите число от 1 до 20: ";
        cin >> m;
    }
    cin.get();

    cout << "введите слова:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "  Слово " << i + 1 << ": ";
        getline(cin, sWords[i]);
    }

    cout << "слова с четными номерами: ";
    for (int i = 1; i < m; i += 2) {
        cout << sWords[i] << " ";
    }
    cout << endl;


}
int main() {
    demchar();
    demstring();
    zadanie_na_massiv();
}