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
    // Элементарные преобразования матриц, используемые в методе Гаусса-Жордана:
    // 1. Перестановка строк (выбор главного элемента) - повышает численную устойчивость
    // 2. Умножение строки на ненулевое число (нормализация строки)
    // 3. Прибавление к одной строке другой строки, умноженной на число (обнуление столбца)

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

        if (maxVal < 1e-9) {
            lead++;  // переходим к следующему столбцу
            r--;     // остаемся на той же строке
            continue;
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
        lead++;

    }
}




int main() {
    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    int M, N; 
    inFile >> M >> N;


    double** matrix = new double*[M];
    for (int i = 0; i < M; i++){
        matrix[i] = new double[N + 1];
        for (int j = 0; j <= N; j++){
            inFile >> matrix[i][j];
        }
    }

    outFile << "Исходная система" << endl;
    printMatrix(matrix, M, N + 1, outFile);

    outFile << "Матрица после преобразований" << endl;
    metod_Gaussa(matrix, M, N);
    printMatrix(matrix, M, N + 1, outFile);
    


    int rank = 0;
    bool noSolution = false;
    for (int i = 0; i < M; i++){
        bool allZerosLeft = true;
        for (int j = 0; j < N; j++){
            if (abs(matrix[i][j]) > 1e-9){
                allZerosLeft = false;
                break;
            }
        }

        if (allZerosLeft && abs(matrix[i][N]) > 1e-9){
            noSolution = true;
            break;
        }
        if (!allZerosLeft) rank++;
    }

    if (noSolution) {
        outFile << "Система не имеет решений." << endl;
    } else if (rank < N) {
        outFile << "Система имеет бесконечно много решений (общее решение)." << endl;
        outFile << "Ранг: " << rank << ", свободных переменных: " << N - rank << endl;

        // общее решение для систем с бесконечным множеством решений
        for (int i = 0; i < rank; i++) {
            int firstIdx = -1;
            for (int j = 0; j < N; j++) {
                if (abs(matrix[i][j]) > 1e-9) {
                    firstIdx = j;
                    break;
                }
            }
            outFile << "x" << firstIdx + 1 << " = " << matrix[i][N];
            for (int j = firstIdx + 1; j < N; j++) {
                if (abs(matrix[i][j]) > 1e-9) {
                    double val = -matrix[i][j];
                    if (val >= 0) outFile << " + " << val << "*x" << j + 1;
                    else outFile << " - " << abs(val) << "*x" << j + 1;
                }
            }
            outFile << endl;
        }
        
    } else {
        outFile << "Единственное решение:" << endl;
        for (int i = 0; i < N; i++) {
            outFile << "x" << i + 1 << " = " << matrix[i][N] << endl;
        }
    }



    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    inFile.close();
    outFile.close();
    cout << "Проверьте файл output.txt" << endl;

    return 0;
}