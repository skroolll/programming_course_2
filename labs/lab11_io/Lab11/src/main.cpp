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

    return 0;
