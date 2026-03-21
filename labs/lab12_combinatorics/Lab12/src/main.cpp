#include <iostream>
#include <vector> 
using namespace std;


//выводы 
void printBoard(const vector <vector<int>> & board, int k) {
    for (int i = 0; i < k; ++i, cout << endl)
        for (int j = 0; j < k; ++j) 
            if (board[i][j]==1){
                cout << "Q ";
            }
            else{
                cout << ". ";
            }
    cout << endl;
}

void printBoard(const vector<int> & boardpro, int k) {
    for (int i = 0; i < k; ++i, cout << endl)
        for (int j = 0; j < k; ++j) 
            if (boardpro[i]==j){
                cout << "Q ";
            }
            else{
                cout << ". ";
            }
    cout << endl;
}



//матрица в лоб
bool proverka_v_lob(const vector <vector<int>> & b, int st, int stl, int raz) {
    for (int i = 1; i <= st; ++i) {
        if (b[st - i][stl]==1) return false; // вверх
        if (stl - i >= 0 && b[st - i][stl - i]==1) return false; // диагональ влево
        if (stl + i < raz && b[st - i][stl + i]==1) return false;  // диагональ вправо
    }
    return true;
}

void v_lob(vector <vector<int>> & board, int st, int raz, int& count) {
    if (st == raz) {
        count++;
        if (raz<=5) printBoard(board, raz);
        return;
    }

    for (int stl = 0; stl < raz; ++stl) {
        if (proverka_v_lob(board, st, stl, raz)) {
            board[st][stl] = 1;
            v_lob(board, st + 1, raz, count);
            board[st][stl] = 0;  // backtracking
        }
    }
}



//алгоритмом с 1-мерным массивом
bool proverka_alg(const vector<int> & q, int st, int stl) {
    for (int i = 0; i < st; ++i){
        if (q[i] == stl) return false;
        if (abs(q[i] - stl) == st - i) return false;
    }
    return true;
}

void alg(vector<int> & boardpro, int st, int raz, int& count) {
    if (st == raz) {
        count++;
        if (raz<=5) printBoard(boardpro, raz);
        return;
    }
    for (int stl = 0; stl < raz; ++stl) {
        if (proverka_alg(boardpro, st, stl)) {
            boardpro[st] = stl;
            alg(boardpro, st + 1, raz, count);
        }
    }
}








int main() {

    return 0;
}
