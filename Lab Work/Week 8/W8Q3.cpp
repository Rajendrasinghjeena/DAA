
// C++ program for the above algorithm

#include <bits/stdc++.h>
using namespace std;
#define V 7
int findMaxVertex(bool visited[], int weights[])
{
    int index = -1;

    int maxW = INT_MIN;

    for (int i = 0; i < V; i++) {

        if (visited[i] == false
            && weights[i] > maxW) {

            maxW = weights[i];

            index = i;
        }
    }
    return index;
}
void printMaximumSpanningTree(int graph[V][V],
                            int parent[])
{

    int MST = 0;

    for (int i = 1; i < V; i++) {

        MST += graph[i][parent[i]];
    }

    cout << "Weight of the maximum Spanning-tree "
        << MST << '\n'
        << '\n';

    cout << "Edges \tWeight\n";

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t"
            << graph[i][parent[i]] << " \n";
    }
}

void maximumSpanningTree(int graph[V][V])
{

    bool visited[V];

    int weights[V];
    int parent[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        weights[i] = INT_MIN;
    }

    weights[0] = INT_MAX;
    parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int maxVertexIndex
            = findMaxVertex(visited, weights);

        visited[maxVertexIndex] = true;

        for (int j = 0; j < V; j++) {

            if (graph[j][maxVertexIndex] != 0
                && visited[j] == false) {

                if (graph[j][maxVertexIndex] > weights[j]) {

                    weights[j] = graph[j][maxVertexIndex];

                    parent[j] = maxVertexIndex;
                }
            }
        }
    }
    printMaximumSpanningTree(graph, parent);
}

int main()
{

    int graph[V][V] = { {0, 0, 7, 5 ,0 ,0 ,0},
    {0, 0, 8, 5 ,0 ,0 ,0},
    {7, 8, 0, 9 ,7 ,0 ,0},
    {5, 0, 9, 0 ,15, 6, 0},
    {0, 5, 7, 15, 0, 8, 9},
    {0, 0, 0, 6 ,8 ,0 ,11},
    {0, 0, 0, 0 ,9 ,11, 0} };

    maximumSpanningTree(graph);

    return 0;
}
