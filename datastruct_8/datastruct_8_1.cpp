#include <iostream>
using namespace std;

#define MAXSIZE 12500

typedef struct {
    int row, col;
    int data=0;
} Triple;

typedef struct {
    Triple data[MAXSIZE+1];
    long r, c, len;
}TSMatrix;

int main(){
    long r, c;
    int data, count=0;
    TSMatrix matrixA, matrixB;
    cin>>r>>c;
    matrixA.r = r; matrixA.c = c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin>>data;
            if (data){
                matrixA.data[count].data = data;
                matrixA.data[count].row = i;
                matrixA.data[count].col = j;
                count++;
            }
        }
    }
    matrixA.len = count;
    matrixB.len = matrixA.len;
    matrixB.r = matrixA.c; matrixB.c = matrixA.r;
    int num[c], position[c];
    int col, t, p, q;
    if (matrixB.len){
        for (int col = 0; col < matrixA.c; ++col) {
            num[col]=0;
        }
        for (t = 0; t < matrixA.len; ++t) {
            num[matrixA.data[t].col]++;
        }
        position[0]=1;
        for (col = 1; col < matrixA.c; ++col) {
            position[col] = position[col-1]+num[col-1];
        }
        for (p = 0; p < matrixA.len; ++p) {
            col = matrixA.data[p].col; q = position[col];
            matrixB.data[q].row = matrixA.data[p].col;
            matrixB.data[q].col = matrixA.data[p].row;
            matrixB.data[q].data = matrixA.data[p].data;
            position[col]++;
        }
    }
    count = 0;
    for (int i = 0; i < matrixB.r; ++i) {
        for (int j = 0; j < matrixB.c; ++j) {
            if (matrixB.data[count].row == i && matrixB.data[count].col == j){
                cout<<matrixB.data[count].data<<' ';
                count++;
            } else {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
    return 0;
}