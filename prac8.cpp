#include <iostream>
using namespace std;
void Degree(int graph[][100], int numVertices) {
    int inDegree[numVertices];
    int outDegree[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (graph[i][j] == 1) {
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i + 1 << ": In-Degree = " << inDegree[i] << ", Out-Degree = " << outDegree[i] << endl;
    }
}
int main() {
    int numVertices;
    cout << "Enter the number of vertices in the graph: ";
    cin >> numVertices;
    int graph[numVertices][100];
    cout << "Enter the adjacency matrix for the directed graph:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }
    Degree(graph, numVertices);
    return 0;
}