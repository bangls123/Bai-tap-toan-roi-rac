#include <bits/stdc++.h>
#include <stdlib.h>
#include<vector>

using namespace std;

void eraseInVector(vector<int> &vec, int value){
    vec.erase(std::remove(vec.begin(), vec.end(), value), vec.end());
}

int main() {
    int n; scanf("%d", &n) ;

    vector<int> vertice1(n);
    vector<int> vertice2(n);

    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        int b; scanf("%d", &b);
        vertice1[i] = a;
        vertice2[i] = b;
    }
//
//    for (int i = 0; i < n; ++i) {
//        cout << vertice1[i] << " " << vertice2[i] << endl;
//    }
    int numberOfVertice = 0;
    for (int i = 0; i < n; ++i) {
        if (numberOfVertice < vertice1[i]) numberOfVertice = vertice1[i];
        if (numberOfVertice < vertice2[i]) numberOfVertice = vertice2[i];
    }

    vector<vector<int> > graph(numberOfVertice + 1);

    for (int i = 0; i < vertice1.size(); ++i) {
        int a = vertice1[i];
        int b = vertice2[i];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

//    for (int i = 0; i < graph.size(); ++i) {
//            cout << i << ": ";
//        for (int j = 0; j < graph[i].size(); ++j) {
//            cout << graph[i][j] << " ";
//        }
//        cout << endl;
//    }

    // con
    vector<int> ruf;
    // cha
    vector<int> prufer ;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            if (graph[j].size() == 1 && j != 0) {
                ruf.push_back(j);
                prufer.push_back(graph[j][0]);

                // remove phan tu j trong
                //graph[graph[j][0]].erase(std::remove(graph[graph[j][0]].begin(), graph[graph[j][0]].end(), j), graph[graph[j][0]].end());
                eraseInVector(graph[graph[j][0]], j);

                //graph[graph[j][0]]
                graph[j].erase(graph[j].begin());
                break;
            }
        }
    }



//    for (int i = 0; i < ruf.size(); ++i) {
//        cout << ruf[i] << " ";
//    }
//    cout << endl;

    for (int i = 0; i < prufer.size() - 1; ++i) {
        cout << prufer[i] << " " ;
    }
    cout << endl;

    return 0;
}
