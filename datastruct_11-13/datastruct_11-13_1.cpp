#include <iostream>
using namespace std;

void init_tree(int line, int tree[], int rank[]){
    for (int i = 0; i < line; ++i) {
        tree[i] = -1;
        rank[i] = 0;
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

int main()
{
    int line;
    cin>>line;
    int matrix[line][line];
    int tree[line];
    int rank[line];
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < line; ++j) {
                cin>>matrix[i][j];
        }
    }

    init_tree(line, tree, rank);

    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < line; ++j) {
            if (matrix[i][j])
                union_vertices(i,j,tree, rank);
        }
    }

    int count=0;
    for (int i = 0; i < line; ++i) {
        if (tree[i] == -1){
            count++;
        }
    }
    cout<<count;

//    for (int k = 0; k < line; ++k) {
//        cout<<k<<": ";
//        for (int i = 0; i < line; ++i) {
//            if(matrix[k][i])
//                cout<<i<<' ';
//        }
//        cout<<endl;
//    }

    return 0;
}

