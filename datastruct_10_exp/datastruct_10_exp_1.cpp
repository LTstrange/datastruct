#include <iostream>
#include <limits>
#include <malloc.h>
#include <cstring>

using namespace std;

#define N 100
#define M 2*N-1

typedef char * HuffmanCode[N+1];

typedef struct {
    int weight;
    int parent;
    int LChild;
    int RChild;
}HTNode, HuffmanTree[M+1];

void select(HuffmanTree ht, int i, int* s1, int* s2){
    int mini=(numeric_limits<int>::max)();
    for (int j = 1; j < i+1; ++j) {
        if (ht[j].parent==0 && ht[j].weight<mini){
            *s1 = j;
            mini =ht[j].weight;
        }
    }
    mini=(numeric_limits<int>::max)();
    for (int k = 1; k < i+1; ++k) {
        if (ht[k].parent==0 && ht[k].weight<mini && k != *s1){
            *s2 = k;
            mini= ht[k].weight;
        }
    }
}

void CrtHuffmanTree(HTNode ht[], int w[], int n){
    for (int i = 1; i <= n; ++i) {
        ht[i].weight = w[i];
        ht[i].parent = 0;
        ht[i].RChild = 0;
        ht[i].LChild = 0;
    }
    int m = 2*n-1;
    for (int i = n+1; i <= m; ++i) {
        ht[i].weight = 0;
        ht[i].parent = 0;
        ht[i].RChild = 0;
        ht[i].LChild = 0;
    }
    int s1, s2;
    for (int i = n+1; i <= m; ++i) {
        select(ht, i-1, &s1, &s2);
        ht[i].weight = ht[s1].weight+ht[s2].weight;
        ht[s1].parent = i;ht[s2].parent = i;
        ht[i].LChild=s1;ht[i].RChild=s2;
    }
}

void PrintHuffmancode(HTNode ht[], HuffmanCode hc, int n){
    char * cd;
    int start, c, p;
    cd =(char*)malloc(n* sizeof(char));
    cd[n-1] = '\0';
    for (int i = 1; i <= n; ++i) {
        start = n-1;
        c = i;p=ht[i].parent;
        while (p != 0){
            --start;
            if (ht[p].LChild == c) cd[start]='0';
            else cd[start]='1';
            c = p; p=ht[p].parent;
        }
        hc[i]=(char*)malloc(n-start* sizeof(char));
        strcpy(hc[i], &cd[start]);
    }
    free(cd);
}

int main() {
    int n;
    cin>>n;
    HuffmanTree ht;
    HuffmanCode hc;
    int nums[n+1];
    for (int i = 1; i <= n; ++i) {
        cin>>nums[i];
    }
    CrtHuffmanTree(ht, nums, n);
    PrintHuffmancode(ht, hc, n);
    for (int j = 0; j < n; ++j) {
        cout<<hc[j+1]<<endl;
    }
    return 0;
}
