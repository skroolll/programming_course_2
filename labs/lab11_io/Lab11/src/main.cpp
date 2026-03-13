#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cctype> 
using namespace std;


int main() {

    //чтение
    FILE *in = fopen("input.txt", "r");

    if (!in) {
        printf("File not found\n");
        return 1;
    }

    char words[50][26];
    int n = 0;

    while (fscanf(in, "%25s", words[n]) != EOF) {
        n++;
    }

    fclose(in);


    //поиск корневых
    int count[50] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){

            if (i == j) continue;

            int len = strlen(words[i]);

            if (strncmp(words[j], words[i], len) == 0 && strlen(words[j]) > len) {
                count[i]++;
            }
        }
    }

    // макс длина и самое важное 
    int longestIndex = -1;
    int importantIndex = -1;

    int maxLen = -1;
    int maxCount = -1; 

    for (int i = 0; i < n; i++){
        if (count[i] > 0){
            int len = strlen(words[i]);

            if (len > maxLen) {
                maxLen = len;
                longestIndex = i;
            }

            if (count[i] > maxCount) {
                maxCount = count[i];
                importantIndex = i;
            }


        }
    }

    //запись
    FILE *out1 = fopen("longest.txt", "w");
    FILE *out2 = fopen("important.txt", "w");

    if (longestIndex == -1) {
        fprintf(out1, "NO");
        fprintf(out2, "NO");
    } else {

        fprintf(out1, "%s\n", words[longestIndex]);

        for (int j = 0; j < n; j++) {
            int len = strlen(words[longestIndex]);

            if (strncmp(words[j], words[longestIndex], len) == 0 &&
                strlen(words[j]) > len) {

                fprintf(out1, "%s\n", words[j]);
            }
        }

        fprintf(out2, "%s\n", words[importantIndex]);

        for (int j = 0; j < n; j++) {

            int len = strlen(words[importantIndex]);

            if (strncmp(words[j], words[importantIndex], len) == 0 &&
                strlen(words[j]) > len) {

                fprintf(out2, "%s\n", words[j]);
            }
        }
    }

    fclose(out1);
    fclose(out2);


    return 0;
}