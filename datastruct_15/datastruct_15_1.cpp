#include <iostream>

using namespace std;

typedef struct {
    int field[3][3];
} state;

int changeCode[9][4] = {{-1, -1, 3,  1},
                      {-1, 0,  4,  2},
                      {-1, 1,  5,  -1},
                      {0,  -1, 6,  4},
                      {1,  3,  7,  5},
                      {2,  4,  8,  -1},
                      {3,  -1, -1, 7},
                      {4,  6,  -1, 8},
                      {5,  7,  -1, -1}
};//0出现在0->8的位置后该和哪些位置交换

void my_hash() {

}

void Input(state &matrix) {
    int tmp;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> tmp;
            matrix.field[i][j] = tmp;
        }
    }
}

void swap(state &target, int a, int b) {
    int tmp;
    tmp = target.field[a / 3][a % 3];
    target.field[a / 3][a % 3] = target.field[b / 3][b % 3];
    target.field[b / 3][b % 3] = target.field[a / 3][a % 3];
}

bool compare_is_same(state a, state b)
{
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a.field[i][j] != b.field[i][j])
            {
                flag = false;
            }
        }
    }
    return flag;
}

int bfs_search(state Source, state End) {
    if (compare_is_same(Source, End)){
        return 0;
    }
    while (true)
    {

    }

}

int main() {
    state Source, End;
    Input(Source);
    Input(End);



    my_hash();
    return 0;
}