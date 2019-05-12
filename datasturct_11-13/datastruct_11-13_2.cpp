#include <iostream>
using namespace std;

typedef struct {
    int from, to, dis;
} Item;

void Input(int edges, Item matrix[])
{
    for (int i = 0; i < edges; ++i) {
        cin>>matrix[i].from>>matrix[i].to>>matrix[i].dis;
    }

}

void Init_tree(int vertexes, int parent[], int rank[])
{
    for (int j = 0; j < vertexes; ++j) {
        parent[j] = -1;
        rank[j] = 0;
    }
}

void sort(int edges, Item matrix[])
{
    Item tmp;
    for (int i = 0; i < edges; ++i) {
        for (int j = i; j < edges; ++j) {
            if (matrix[i].dis > matrix[j].dis){
                tmp = matrix[i];
                matrix[i] = matrix[j];
                matrix[j] = tmp;
            }
        }
    }
}

int find_root(int x, int parent[]){
    int x_root = x;
    while(parent[x_root] != -1){
        x_root = parent[x_root];
    }
    return x_root;
}

int union_vertices(int x, int y, int parent[], int rank[]){
    int x_root = find_root(x, parent);
    int y_root = find_root(y, parent);
    if (x_root == y_root)
        return 0;
    else{
        if (rank[x_root]>rank[y_root])
            parent[y_root] = x_root;
        else if (rank[y_root]> rank[x_root])
            parent[x_root] = y_root;
        else{
            parent[x_root] = y_root;
            rank[y_root]++;
        }
        return 1;
    }
}

void MiniSpanTree_Prim(Item matrix[], int vertexes, int edges)
{
    cout<<"...."<<endl;
}

void MiniSpanTree_Kruskal(Item matrix[], int vertexes, int edges)
{

    int parent[vertexes];
    int rank[vertexes];
    sort(edges, matrix);
    Init_tree(vertexes, parent, rank);
    int k=0;
    int result=0;
    for (int i = 0; i < edges; ++i) {
        if (k == vertexes-1)
            break;
        if (union_vertices(matrix[i].from-1, matrix[i].to-1, parent, rank)){
            result+=matrix[i].dis;
            k++;
        }
    }
    cout<<result<<endl;
}

int main()
{
    int edges, vertexes;
    cin>>vertexes>>edges;
    Item matrix[edges];
    Input(edges, matrix);
    MiniSpanTree_Prim(matrix, vertexes, edges);
    MiniSpanTree_Kruskal(matrix, vertexes, edges);

    return 0;
}
