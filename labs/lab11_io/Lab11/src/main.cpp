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
    int length;
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

    if (file == NULL) {
        cout << "Ошибка открытия файла " << filer << endl;
        return 0;
    }


    char buffer[BUFFER_SIZE];
    int wordCount = 0;

    while (fgets(buffer, BUFFER_SIZE, file) != NULL && wordCount < MAX_WORDS) {

        for (int i = 0; buffer[i] != '\0' && wordCount < MAX_WORDS; i++) {
            if (isspace(buffer[i]))
                continue;

            int j = 0;
            while (!isspace(buffer[i]) && buffer[i] != '\0' && j < MAX_LEN) {
                words[wordCount].word[j] = buffer[i];
                i++;
                j++;
            }

            words[wordCount].word[j] = '\0';
            words[wordCount].length = j;
            words[wordCount].rootForCount = 0;
            words[wordCount].isRoot = false;
            wordCount++;

        }
    }
    fclose(file);
    return wordCount;
}


//поиск корн слов
void findRootWords(WordInfo words[], int wordCount) {

    for (int i = 0; i < wordCount; i++) {
        for (int j = 0; j < wordCount; j++) {
             if (i == j) continue;

             if (words[i].length <= words[j].length && isRootWord(words[i].word, words[j].word)) {
                words[i].rootFor[words[i].rootForCount] = j;
                words[i].rootForCount++;
                words[i].isRoot = true;
             }
        }
    }
}



//самое длинное корн слово
int findLongestRootWord(WordInfo words[], int wordCount){
    int maxLength = 0;
    int longestIndex = -1;

    for (int i = 0; i < wordCount; i++) {
        if (words[i].isRoot && words[i].length > maxLength){
            maxLength = words[i].length;
            longestIndex = i;
        }
    }

    return longestIndex;

}


//самое важное корн слово
int findMostImportantWord(WordInfo words[], int wordCount){
    int maxCount = 0;
    int importantIndex = -1;

    for (int i = 0; i < wordCount; i++){
        if (words[i].isRoot && words[i].rootForCount > maxCount){
            maxCount = words[i].rootForCount;
            importantIndex = i;
        }
    }

    return importantIndex;

}


//запись самого длинного корн слова
void writeLongestRootToFile(const char* filew, WordInfo words[], int wordCount, int longestIndex){
    FILE* file = fopen(filew, "w");
    if (file == NULL) return;

    if (longestIndex == -1){
        fprintf(file, "NO\n");
    }else{
        fprintf(file, "%s\n", words[longestIndex].word);
        for (int i = 0; i < words[longestIndex].rootForCount; i++){
            int idx = words[longestIndex].rootFor[i];
            fprintf(file, "%s\n", words[idx].word);
        }
    }

    fclose(file);

}



int main() {
    WordInfo words[MAX_WORDS];
    int wordCount = readWordsFromFile("words.txt", words);

    if (wordCount == 0) {
        cout << "Нет слов для обработки" << endl;
        return 0;  
    }

    findRootWords(words, wordCount);
    int longestIndex = findLongestRootWord(words, wordCount);
    int importantIndex = findMostImportantWord(words, wordCount);

    writeLongestRootToFile("longest_root.txt", words, wordCount, longestIndex);




    return 0;
}