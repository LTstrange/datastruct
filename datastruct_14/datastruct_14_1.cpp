#include <iostream>
#include <limits>

#define INFINITY (numeric_limits<int>::max)()

using namespace std;

void ShortestPath_DIJ(int *matrix, int n, int s) {
    bool final[n];
    int dis[n];
    for (int i = 0; i < n; ++i) {
        final[i] = 0;
        dis[i] = matrix[s * n + i];
        if (dis[i])
            final[i] = 1;
        else
            dis[i] = INFINITY;
    }
    dis[s] = -1;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            if (final[i]) {
                for (int j = 0; j < n; ++j) {
                    if (matrix[i*n+j] && (matrix[i*n+j]+dis[i]<dis[j])){
                        dis[j] = matrix[i*n+j]+dis[i];
                        final[j] = 1;
                    }
                }
            }

        }
    }
    for (int l = 0; l < n; ++l) {
        if (dis[l] != -1){
            if (dis[l] != INFINITY){
                cout<< dis[l] <<' ';
            } else{
                cout<<-1<<' ';
            }
        }
    }
}

void Input(int n, int *matrix) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i * n + j];
        }
    }
}

int main() {
    int n, s;
    cin >> n >> s;

    int adj_matrix[n][n];
    Input(n, (int *) adj_matrix);

    ShortestPath_DIJ((int *)adj_matrix, n, s);


    return 0;
}
