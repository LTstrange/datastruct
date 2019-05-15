#include <iostream>

using namespace std;

int main() {
    int vertexes;
    cin >> vertexes;
    int adj_matrix[vertexes][vertexes];
    for (int i = 0; i < vertexes; ++i) {
        for (int j = 0; j < vertexes; ++j) {
            cin >> adj_matrix[i][j];
        }
    }

    int count = vertexes;
    bool flag = 1, E_flag = 0;
    bool b_vec[vertexes];
    for (int i = 0; i < vertexes; ++i) {
        b_vec[i] = 1;
    }
    while (count) {
        E_flag = 1;
        for (int i = 0; i < vertexes; --i) {
            if (b_vec[i]) {
                for (int j = 0; j < vertexes; ++j) {
                    if (adj_matrix[j][i]) {
                        flag = 0;
                    }
                }
                if (flag) {
                    cout << i << ' ';
                    b_vec[i] = 0;
                    count--;
                    E_flag = 0;
                    for (int j = 0; j < vertexes; ++j) {
                        adj_matrix[i][j] = 0;
                    }
                }
                flag = 1;
            }
        }
        if (E_flag) {
            cout << "ERROR" << endl;
            return 0;
        }
    }
    return 0;
}

