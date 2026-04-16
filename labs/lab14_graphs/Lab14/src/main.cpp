#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    ifstream in1("input.txt");
    int u, v, max = 0;
    vector<pair<int, int>> edgeList;

    while (in1 >> u >> v) {
        edgeList.push_back({u, v});
        if (u > max) max = u;
        if (v > max) max = v;
    }
    in1.close();

    //создание и заполнение матр.смежн.
    vector<vector<int>> matrix(max, vector<int>(max, 0));
    for (auto edge : edgeList) {
        matrix[edge.first - 1][edge.second - 1] = 1;
        matrix[edge.second - 1][edge.first - 1] = 1; 
    }

    // запись в output1.txt
    ofstream out1("output1.txt");
    out1 << max << endl; 
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            out1 << matrix[i][j] << " ";
        }
        out1 << endl;
    }
    out1.close();

    return 0;
}
