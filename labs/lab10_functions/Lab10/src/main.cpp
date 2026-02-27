#include <iostream>
using namespace std;


const int MAX_VALUE = 17;
const int VALUE_COUNT = 18;

void pack(const int source[], int n, int packed[]) {
    for (int i = 0; i < VALUE_COUNT; i++) packed[i] = 0;
    for (int i = 0; i < n; i++) packed[source[i]]++;
}

void unpack(const int packed[], int restored[], int n) {
    int index = 0;
    for (int val = 0; val < VALUE_COUNT; val++) {
        for (int count = 0; count < packed[val]; count++) {
            restored[index++] = val;
        }
    }
}

int main() {
    
    return 0;
}
