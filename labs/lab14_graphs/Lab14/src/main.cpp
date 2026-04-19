#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

    // первый номер
    
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




    // второй номер

    ifstream in2("output1.txt");
    int n;
    in2 >> n;
    vector<vector<int>> m2(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            in2 >> m2[i][j];
    in2.close();

    vector<int> sosed; 
    vector<int> head;
    
    for (int i = 0; i < n; i++) {
        head.push_back(sosed.size() + 1); 
        for (int j = 0; j < n; j++) {
            if (m2[i][j] == 1) {
                sosed.push_back(j + 1);
            }
        }
    }
    head.push_back(sosed.size() + 1); 

    // запись в output2.txt
    ofstream out2("output2.txt");
    out2 << n << endl; 
    for (int x : sosed) out2 << x << " ";
    out2 << endl;
    for (int x : head) out2 << x << " ";
    out2.close();




    //третий номер
    
    ifstream in3("output2.txt");
    int numNodes;
    in3 >> numNodes;

    vector<int> adj3, head3;
    int temp;
    vector<int> allData;
    while (in3 >> temp) allData.push_back(temp);
    in3.close();

   
    int headSize = numNodes + 1;
    for (int i = 0; i < (int)allData.size() - headSize; i++) {
        adj3.push_back(allData[i]);
    }

    for (int i = allData.size() - headSize; i < (int)allData.size(); i++) {
        head3.push_back(allData[i]);
    }
    
    ofstream out3("output3.txt");
    for (int i = 0; i < numNodes; i++) {
        int start = head3[i] - 1;
        int end = head3[i + 1] - 1;

        for (int k = start; k < end; k++) {
            int neighbor = adj3[k];

            if ((i + 1) < neighbor) {
                out3 << i + 1 << " " << neighbor << endl;
            }
        }
    }
    out3.close();

    cout << "Проверьте файлы output1.txt, output2.txt, output3.txt" << endl;

    return 0;
}
