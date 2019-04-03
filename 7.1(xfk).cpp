#include <iostream>
using namespace std;

void KMP(){
    int m,n;
    string A,B;
    int next[100];
    next[0] = -1;
    cin>>A>>B;
    n=A.size();
    m=B.size(); //求长度

    for (int i=1;i<m;i++){
        int j=next[i-1];
        while((B[j+1]!=B[i])&&(j>=0))
            j = next[j];
        if(B[j+1]==B[i]){
            next[i]=j+1;
        }
        else{
            next[i] = -1;
        }
    }   //求next数组


    int i=0,j=0;
    while(i<n){
        if(A[i]==B[j]){
            i++;j++;
            if(j==m){
                cout<<i-m+1<<endl;// 找到 输出 结束
                return ;
            }
        }
        else{
            if(j==0) i++;
            else j =next[j-1]+1;
        }
    }
    cout<<0<<endl;return;  //没找到 输出0 结束
}

int main()
{   int i=3; //3组数据
    while(i--)
        KMP();
}



