#include <iostream>

using namespace std;

void Init_adj_matrix(int* matrix, int vertexes, int edges){
    for (int i = 0; i < vertexes; ++i) {
        for (int j = 0; j < vertexes; ++j) {
            matrix[i*vertexes+j] = -1;
        }
    }

    for (int i = 0, from, to, dis; i < edges; ++i) {
        cin >> from >> to >> dis;
        matrix[from*vertexes+to] = dis;
    }
}

int main() {
    int vertexes, edges;
    cin >> vertexes >> edges;
    int adj_matrix[vertexes][vertexes];

    Init_adj_matrix((int*)adj_matrix, vertexes, edges);

    int ve[vertexes];
    return 0;
}
