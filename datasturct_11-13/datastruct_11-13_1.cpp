#include <iostream>
using namespace std;

int main()
{
    int line;
    cin>>line;
    int matrix[line][line];
    int tree[line];
    for (int i = 0; i < line; ++i) {
        for (int j = 0; j < line; ++j) {
            cin>>matrix[i][j];
        }
    }

    for (int k = 0; k < line; ++k) {
        tree[k]=0;
    }

    int type=1;
    for (int i = 0; i < line; ++i) {
        if (tree[i] == 0){
            tree[i] = type;
            type++;
        }
        for (int j = 0; j < line; ++j) {
            if (matrix[i][j]){
                tree[j] = tree[i];
            }
        }
    }

    cout<<type-1<<endl;
    return 0;
}