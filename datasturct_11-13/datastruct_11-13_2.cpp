#include <iostream>
using namespace std;

typedef struct {
    int from, to, dis;
} Item;

void Input(int vertexes, int edges, Item matrix[], int parent[])
{
    for (int i = 0; i < edges; ++i) {
        cin>>matrix[i].from>>matrix[i].to>>matrix[i].dis;
    }
    for (int j = 0; j < vertexes; ++j) {
        parent[j] = -1;
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

void MiniSpanTree_Prim(int matrix[][3]){

}

void MiniSpanTree_Kruskal(int matrix[][3])
{

}

int main()
{
    int edges, vertexes;
    cin>>vertexes>>edges;
    Item matrix[edges];
    int parent[vertexes];
    Input(vertexes, edges, matrix, parent);
    sort(edges, matrix);

    return 0;
}
