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
            if (boardpro[j]==i){
                cout << "Q ";
            }
            else{
                cout << ". ";
            }
    cout << endl;
}


int main() {

    return 0;
}
