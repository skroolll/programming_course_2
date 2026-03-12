#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cctype> 
using namespace std;

const int MAX_WORDS = 50;  
const int MAX_LEN = 25;       
const int BUFFER_SIZE = 1024;


struct WordInfo{
    char word[MAX_LEN+1];
    int lenght;
    int rootFor[MAX_WORDS];
    int rootForCount;
    bool isRoot;
};


// является ли слово корнем для другого
bool isRootWord(const char* root, const char* word) {
    for (int i = 0; root[i] != '\0' && word[i] != '\0'; i++) {
        if (root[i] != word[i])
            return false;
    }
    return true;
}


//чтение из файла
int readWordsFromFile(const char* filer, WordInfo words[]) {
    FILE* file = fopen(filer, "r");
    
    if (filer == NULL) {
        cout << "Ошибка открытия файла " << filer << endl;
        return 0;
    }

}

int main() {
    



    return 0;
}
