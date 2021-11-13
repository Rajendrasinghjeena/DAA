#include <iostream>
#include<limits>
#include<vector>
using namespace std;

int minnode(int n, int keyval[], bool mstset[]) {
    int mini = numeric_limits<int>::max();

    int mini_index;
    for (int i = 0; i < n; i++) {
        if (mstset[i] == false && keyval[i] < mini) {
        mini = keyval[i], mini_index = i;
        }
    }
    return mini_index;
}
void findcost(int n, vector<vector<int>> city) {

    int parent[n];

    int keyval[n];
    bool mstset[n];

    for (int i = 0; i < n; i++) {
        keyval[i] = numeric_limits<int>::max();
        mstset[i] = false;
    }
    parent[0] = -1;
    keyval[0] = 0;
    for (int i = 0; i < n - 1; i++) {

        int u = minnode(n, keyval, mstset);

        mstset[u] = true;

        for (int v = 0; v < n; v++) {

        if (city[u][v] && mstset[v] == false &&
            city[u][v] < keyval[v]) {
            keyval[v] = city[u][v];
            parent[v] = u;
        }
        }
    }
    int cost = 0;
    for (int i = 1; i < n; i++)
        cost += city[parent[i]][i];
    cout << "Minimum Spanning Weight: "<<cost << endl;       
}

int main() {

int n1 = 7;
vector<vector<int>> city1 = {{0, 0, 7, 5 ,0 ,0 ,0},
                            {0, 0, 8, 5 ,0 ,0 ,0},
                            {7, 8, 0, 9 ,7 ,0 ,0},
                            {5, 0, 9, 0 ,15, 6, 0},
                            {0, 5, 7, 15, 0, 8, 9}, 
                            {0, 0, 0, 6 ,8 ,0 ,11},
                            {0, 0, 0, 0 ,9 ,11, 0}};
    findcost(n1, city1);
    return 0; 
} 
