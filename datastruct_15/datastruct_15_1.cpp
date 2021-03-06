#include<cstdio>
#include<queue>
#include <iostream>
#include <cmath>

using namespace std;
char arr[10], brr[10] = "123804765";

struct node {
    int num, step, cost, zeroPos;

    bool operator<(const node &a) const {
        return cost > a.cost;
    }

    node(int n, int s, int p) {
        num = n, step = s, zeroPos = p;
        setCost();
    }

    void setCost() {
        char a[10];
        int c = 0;
        sprintf(a, "%09d", num);
        for (int i = 0; i < 9; i++)
            if (a[i] != brr[i])
                c++;
        cost = c + step;
    }
};

int changeId[9][4] = {{-1, -1, 3, 1},
                      {-1, 0,  4, 2},
                      {-1, 1,  5, -1},
                      {0,  -1, 6, 4},
                      {1,  3,  7, 5},
                      {2,  4,  8, -1},
                      {3,  -1, -1, 7},
                      {4,  6,  -1, 8},
                      {5,  7,  -1, -1}};
const int M = 2E+6, N = 1000003;//362897;
int hashTable[M];//hashtable中key为hash值，value为被hash的值
int Next[M], des = 123804765;//next表示如果在某个位置冲突，则冲突位置存到hashtable[next[i]]
priority_queue<node> que;//优先级队列
int Hash(int n) {
    return n % N;
}

bool tryInsert(int n) {
    int hashValue = Hash(n);
    while (Next[hashValue]) {//如果被hash出来的值得next不为0则向下查找
        if (hashTable[hashValue] == n)//如果发现已经在hashtable中则返回false
            return false;
        hashValue = Next[hashValue];
    }//循环结束hashValue指向最后一个hash值相同的节点
    if (hashTable[hashValue] == n)//再判断一遍
        return false;
    int j = N - 1;//在N后面找空余空间，避免占用其他hash值得空间造成冲突
    while (hashTable[++j]);//向后找一个没用到的空间
    Next[hashValue] = j;
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
    node tempN(start, 0, zeroPos);
    que.push(tempN);
    while (!que.empty()) {
        tempN = que.top();
        que.pop();
        sprintf(temp, "%09d", tempN.num);
        int pos = tempN.zeroPos, k;
        for (int i = 0; i < 4; i++) {
            if (changeId[pos][i] != -1) {
                swap(temp, pos, changeId[pos][i]);
                sscanf(temp, "%d", &k);
                if (k == des)return tempN.step + 1;
                if (tryInsert(k)) {//插入新状态成功，则说明新状态没有被访问过
                    node tempM(k, tempN.step + 1, changeId[pos][i]);
                    que.push(tempM);
                }
                swap(temp, pos, changeId[pos][i]);
            }
        }
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