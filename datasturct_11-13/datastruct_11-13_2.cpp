#include <iostream>
#include <limits>

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

void To_matrix(int *adj_matrix, int edges, int vertexes, Item edges_matrix[])
{
    for (int j = 0; j < vertexes; ++j) {
        for (int i = 0; i < vertexes; ++i) {
            *(adj_matrix+i*vertexes+j) = 0;
        }
    }
    int from, to, dis;
    for (int i = 0; i < edges; ++i) {
        from = edges_matrix[i].from-1;
        to = edges_matrix[i].to-1;
        dis = edges_matrix[i].dis;
        *(adj_matrix+from*vertexes+to) = dis;
        *(adj_matrix+to*vertexes+from) = dis;
    }
}

void MiniSpanTree_Prim(Item edges_matrix[], int vertexes, int edges)
{
    int adj_matrix[vertexes][vertexes];
    To_matrix((int*)adj_matrix, edges, vertexes, edges_matrix);
    int sum=0;
    int min, k;
    int lowcost[vertexes];
    int adjvex[vertexes];
    for (int i = 0; i < vertexes; ++i) {
        adjvex[i] = 0;
        lowcost[i] = adj_matrix[0][i];
    }
    lowcost[0] = -1;
    for (int i = 0; i < vertexes; ++i) {
        min = (numeric_limits<int>::max)();
        k = -1;
        for (int j = 0; j < vertexes; ++j) {
            if (lowcost[j]>0 && min>lowcost[j]){
                min = lowcost[j];
                k = j;
            }
        }
        if (k != -1)
        {
            lowcost[k] = -1;
            sum += min;
            for (int j = 0; j < vertexes; ++j) {
                if (lowcost[j] == 0 || adj_matrix[k][j] > 0 && adj_matrix[k][j] < lowcost[j])
                {
                    lowcost[j] = adj_matrix[k][j];
                    adjvex[j] = k;
                }
            }
        }
    }
    cout<<sum<<endl;
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
