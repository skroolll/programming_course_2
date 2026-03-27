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

void metod_Gaussa(double** matrix, int M, int N){
    int lead = 0;
    for (int r = 0; r < M; r++){
        if (lead >= N) return;
        int i = r;


        // поиск ведущего(максимального ненулевого) элемента
        int maxRow = r;
        double maxVal = abs(matrix[r][lead]);
        for (int i = r + 1; i < M; i++){
            if (abs(matrix[i][lead]) > maxVal){
                maxVal = abs(matrix[i][lead]);
                maxRow = i;
            }
        }
        swap(matrix[maxRow], matrix[r]); 


        //нормализация строки
        double div = matrix[r][lead];
        for (int j = 0; j <= N; j++) {
            matrix[r][j] /= div;
        }


        //обнуление столбца
        for (int k = 0; k < M; k++) {
            if (k != r){
                double factor = matrix[k][lead];
                for (int j = 0; j <= N; j++){
                    matrix[k][j] -= factor * matrix[r][j];
                }
            }
        }


        

    }
}




int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int M, N; 
    inFile >> M >> N;


    return 0;
}
