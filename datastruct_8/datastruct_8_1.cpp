#include <iostream>
using namespace std;

#define MAXSIZE 1000

typedef struct {
    int row, col;
    int data=0;
} Triple;

typedef struct {
    Triple data[MAXSIZE+1];
    int m, n, len;
}TSMatrix;

int main(){
    int r, c;
    TSMatrix matrix;

    cin>>r>>c;
    return 0;
}