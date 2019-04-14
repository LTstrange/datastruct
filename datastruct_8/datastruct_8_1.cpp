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
    TSMatrix matrix;
    cin>>r>>c;
    matrix.r = r;
    matrix.c = c;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin>>data;
            if (!data){
                matrix.data[count].data = data;
                matrix.data[count].row = i;
                matrix.data[count].col = j;
                count++;
            }
        }
    }
    count = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (matrix.data[count].row == i && matrix.data[count].col == j){
                cout<<matrix.data[count].data<<' ';
                count++;
            } else {
                cout<<'0 ';
            }
        }
        cout<<endl;
    }
    return 0;
}