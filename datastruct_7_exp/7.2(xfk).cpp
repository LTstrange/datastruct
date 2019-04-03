#include <iostream>
using namespace std;
//暴力求解
int main()
{   string A,B;
    cin>>A>>B;
    int start =0;
    int lenA=A.size(),lenB=B.size();  //求出A,B的长度
    int len =0; //记录子串的长度
    int lenm =0;  // 记录最长的子串的长度
    for (int i=0;i<lenA;i++){
        for (int j=0;j<lenB;j++){
            int p=i,q=j;len=0;
            while(p<lenA && q<lenB){
                if(A[p]!=B[q]) break;
                p++;q++;len++;
            }
            if(len>lenm) {
                    lenm =len;
                    start =i;
            }
        }}
        int i=0;
        while(i++<lenm){
            cout<<A[start+i-1];
        }
        if(lenm==0)
            cout<<"no";
}


