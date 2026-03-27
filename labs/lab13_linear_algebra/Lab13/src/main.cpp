#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

void printMatrix(double** matrix, int rows, int cols, ostream& out) {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            out << setw(10) << setprecision(3) << fixed << matrix[i][j] << " ";
        }
        out << endl;
    }
    out << endl;
}





int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int M, N; 
    inFile >> M >> N;


    return 0;
}
