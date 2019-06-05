#include <iostream>
#include <math.h>
#include <queue>

#define MAX_num 392880

using namespace std;

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

void Initnext(bool next[]) {
    for (int i = 0; i < MAX_num; ++i) {
        next[i] = false;
    }
}

int my_hash(state target) {
    int tmp = 0;
    for (int i = 0; i < 9; ++i) {
        tmp += target.field[i / 3][i % 3] * (pow(10, 8 - i));
    }
    return tmp % MAX_num;
}

void Input(int &matrix) {
    int tmp;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> tmp;
            matrix.field[i][j] = tmp;
            if (tmp == 0) {
                matrix = i * 3 + j;
            }
        }
    }
}

state Swap(state target, int a, int b) {
    int tmp;
    tmp = target.field[a / 3][a % 3];
    target.field[a / 3][a % 3] = target.field[b / 3][b % 3];
    target.field[b / 3][b % 3] = tmp;
    return target;
}

bool compare_is_same(state a, state b) {
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a.field[i][j] != b.field[i][j]) {
                flag = false;
            }
        }
    }
    return flag;
}

bool in_hashTable(state target, state hashTable[], const bool next[]) {
    int hashValue = my_hash(target);
    while (next[hashValue] && !compare_is_same(hashTable[hashValue], target)) {
        hashValue++;
    }
    if (compare_is_same(hashTable[hashValue], target)) {
        return true;
    } else {
        return false;
    }
}

bool tryInsert(state target, state hashTable[], bool next[]) {
    int hashValue = my_hash(target);
    while (next[hashValue]) {
        if (compare_is_same(hashTable[hashValue], target)) {
            return false;
        }
        hashValue++;
    }
    hashTable[hashValue] = target;
    return true;
}

int bfs_search(state Source, state End, state hash_table[], bool next[]) {
    int step = 0;
    int len = 0;
    queue<int> currentState, tmpQueue;

    tryInsert(Source, hash_table, next);
    currentState.push(Source);

    state priState, laterState;
    while (!in_hashTable(End, hash_table, next)) {
        while (!currentState.empty()) {
            priState = currentState.front();
            for (int j = 0; j < 4; ++j) {
                int SwapTo = changeCode[priState.pos][j];
                if (SwapTo != -1) {
                    laterState = Swap(priState, priState.pos, SwapTo);
                    if (tryInsert(priState, hash_table, next)) {
                        tmpQueue.push(laterState);
                    }
                }
            }
        }
        currentState = tmpQueue;
        step++;
    }
    return step;

}

int main() {
    int Source, End;
    Input(Source);
    Input(End);

    int result;
    int hash_table[MAX_num];
    bool next[MAX_num];
//    Initnext(next);
//
//    result = bfs_search(Source, End, hash_table, next);
//
//    cout << result << endl;
//    return 0;
}