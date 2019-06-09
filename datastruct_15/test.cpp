#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;
char arr[10];
int changeId[9][4] = {{-1, -1, 3,  1},
                      {-1, 0,  4,  2},
                      {-1, 1,  5,  -1},
                      {0,  -1, 6,  4},
                      {1,  3,  7,  5},
                      {2,  4,  8,  -1},
                      {3,  -1, -1, 7},
                      {4,  6,  -1, 8},
                      {5,  7,  -1, -1}};
const int M = 2E+6, N = 1000003;//362897;
int hashTable[M];//hashtable中key为hash值，value为被hash的值 
int my_next[M];//next表示如果在某个位置冲突，则冲突位置存到hashtable[my_next[i]]
int que[N][3], des = 264137058;

int my_hash(int n) {
    return n % N;
}

bool tryInsert(int n) {
    int hashValue = my_hash(n);
    while (my_next[hashValue]) {//如果被hash出来的值得next不为0则向下查找
        if (hashTable[hashValue] == n)//如果发现已经在hashtable中则返回false
            return false;
        hashValue = my_next[hashValue];
    }//循环结束hashValue指向最后一个hash值相同的节点
    if (hashTable[hashValue] == n)//再判断一遍
        return false;
    int j = N - 1;//在N后面找空余空间，避免占用其他hash值得空间造成冲突
    while (hashTable[++j]);//向后找一个没用到的空间
    my_next[hashValue] = j;
    hashTable[j] = n;
    return true;
}

void swap(char *ch, int a, int b) {
    char c = ch[a];
    ch[a] = ch[b];
    ch[b] = c;
}

int bfsHash(int start, int zeroPos) {
    char temp[10];
    int head = 0, tail = 1;
    que[head][0] = start, que[head][1] = zeroPos, que[head][2] = 0;
    while (head != tail) {
        sprintf(temp, "%09d", que[head][0]);
        int pos = que[head][1], k;
        for (int i = 0; i < 4; i++) {
            if (changeId[pos][i] != -1) {
                swap(temp, pos, changeId[pos][i]);
                sscanf(temp, "%d", &k);
                if (k == des)return que[head][2] + 1;
                if (tryInsert(k)) {//插入新状态成功，则说明新状态没有被访问过
                    que[tail][0] = k;
                    que[tail][1] = changeId[pos][i];
                    que[tail][2] = que[head][2] + 1;
                    tail++;
                }
                swap(temp, pos, changeId[pos][i]);
            }
        }
        head++;
    }
}

int Input(int &matrix) {
    int tmp, p;
    matrix = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> tmp;
            matrix += tmp * (int) pow(10, 8 - (i * 3 + j));
            if (tmp == 0) {
                p = i * 3 + j;
            }
        }
    }
    return p;
}

int main() {
    int n, k, b = 0;

    Input(des);

    k = Input(n);

    if (n != des)
        b = bfsHash(n, k);
    printf("%d", b);
    return 0;
}