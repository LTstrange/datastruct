#include <iostream>
using namespace std;
//�������
int main()
{   string A,B;
    cin>>A>>B;
    int start =0;
    int lenA=A.size(),lenB=B.size();  //���A,B�ĳ���
    int len =0; //��¼�Ӵ��ĳ���
    int lenm =0;  // ��¼����Ӵ��ĳ���
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


