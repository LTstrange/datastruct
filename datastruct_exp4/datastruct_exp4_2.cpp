#include <iostream>
#include <limits>

using namespace std;

typedef struct {
    int from, to, dis;
}edge_elem;

void Init_matrix(int *matrix, edge_elem edge_matrix[], int vertexes, int edges) {
    for (int i = 0; i < vertexes; ++i) {
        for (int j = 0; j < vertexes; ++j) {
            matrix[i * vertexes + j] = -1;
        }
    }

    for (int i = 0, from, to, dis; i < edges; ++i) {
        cin >> from >> to >> dis;
        matrix[from * vertexes + to] = dis;
        edge_matrix[i].from = from;
        edge_matrix[i].to = to;
        edge_matrix[i].dis = dis;
    }
}

void Init_ve_vl(int ve[], int vl[], int vertexes) {
    for (int i = 0; i < vertexes; ++i) {
        ve[i] = -1;
    }
    for (int i = 0; i < vertexes; ++i) {
        vl[i] = (numeric_limits<int>::max)();
    }
}

void get_ve(int ve[], int *matrix, int vertexes) {
    ve[0] = 0;
    for (int i = 0; i < vertexes; ++i) {
        for (int j = 0; j < vertexes; ++j) {
            if (matrix[i * vertexes + j] != -1 && (matrix[i * vertexes + j] + ve[i] > ve[j])) {
                ve[j] = matrix[i * vertexes + j] + ve[i];
            }
        }
    }
}

void get_vl(int vl[], int *matrix, int vertexes, int end) {
    vl[vertexes - 1] = end;
    for (int i = vertexes - 1; i >= 0; --i) {
        for (int j = 0; j < vertexes; ++j) {
            if (matrix[j * vertexes + i] != -1 && (vl[i] - matrix[j * vertexes + i] < vl[j])) {
                vl[j] = vl[i] - matrix[j * vertexes + i];
            }
        }
    }
}

void get_e(int e[], int ve[], edge_elem edge_matrix[], int edges) {
    for (int i = 0; i < edges; ++i) {
        e[i] = ve[edge_matrix[i].from];
    }
}

void get_l(int l[], edge_elem edge_matrix[], int vl[], int edges, int vertexes) {
    for (int i = 0; i < edges; ++i) {
        l[i] = vl[edge_matrix[i].to] - edge_matrix[i].dis;
    }
}

void compare(int e[], int l[], int edges, edge_elem edge_matrix[]){
    for (int i = 0; i < edges; ++i) {
        if (e[i] == l[i]){
            cout<<edge_matrix[i].from<<' '<<edge_matrix[i].to<<endl;
        }
    }
}

int main() {
    int vertexes, edges;
    cin >> vertexes >> edges;

    int adj_matrix[vertexes][vertexes];
    edge_elem edge_matrix[edges];

    Init_matrix((int *) adj_matrix, edge_matrix, vertexes, edges);

    int ve[vertexes], vl[vertexes];
    int l[edges], e[edges];

    Init_ve_vl(ve, vl, vertexes);

    get_ve(ve, (int *) adj_matrix, vertexes);

    get_vl(vl, (int *) adj_matrix, vertexes, ve[vertexes - 1]);

    get_e(e, ve, edge_matrix, edges);

    get_l(l, edge_matrix, vl, edges, vertexes);

    compare(e, l, edges, edge_matrix);

    return 0;
}
