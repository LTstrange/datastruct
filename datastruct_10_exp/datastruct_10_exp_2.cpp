#include <iostream>
#include <string>
#include <vector>
#include <malloc.h>

using namespace std;

typedef struct Node{
    char data;
    struct Node * LChild;
    struct Node * RChild;
}BiTNode, * BiTree;

void BuildTree(string Pre, string Mid, BiTree &Root, int i, int A[], string C_Mid){
    if (Pre.length() == 0){
        Root = NULL;
        return;
    }
    Root = (BiTree)malloc(sizeof(BiTNode));
    Root->data = Pre[0];
    int ind = Mid.find(Pre[0]);
    string LMid = Mid.substr(0, ind);
    string LPre = Pre.substr(1, ind);
    string RMid = Mid.substr(ind+1);
    string RPre = Pre.substr(ind+1);
    A[C_Mid.find(Pre[0])] = i;
    BuildTree(LPre, LMid, Root->LChild, i+1, A, C_Mid);
    BuildTree(RPre, RMid, Root->RChild, i+1, A, C_Mid);
}

//void Find(BiTree &Root, string tar, string Mid){
//    Array A;
//    A.Mid = Mid;
//
//}

int main(){
    string Pre, Mid, tar;
    BiTree Root;
    cin>>Pre>>Mid;
    int A[Mid.length()];
    Root = (BiTNode*)malloc(sizeof(BiTNode));
    BuildTree(Pre, Mid, Root, 0, A, Mid);
    cin>>tar;
    int ind0 = Mid.find(tar[0]);
    int ind1 = Mid.find(tar[1]);
    if ((ind0+ind1) == ind0*2-1 || (ind0+ind1) == ind1*2-1) {
        cout << "NULL" << endl;
        return 0;
    }
    string l0, l1;
    if (ind0 < ind1){
        int temp=ind0;
        for (int i=ind0;i<ind1;i++){
            if (A[i]<A[temp]){
                l0.push_back(Mid[i]);
                temp = i;
            }
        }
        temp = ind1;
        for (int i=ind1;i>ind0;i--){
            if (A[i]<A[temp]){
                l1.push_back(Mid[i]);
                temp = i;
            }
        }
    } else{
        int temp=ind1;
        for (int i=ind1;i<ind0;i++){
            if (A[i]<A[temp]){
                l1.push_back(Mid[i]);
                temp = i;
            }
        }
        temp = ind0;
        for (int i=ind0;i>ind1;i--){
            if (A[i]<A[temp]){
                l0.push_back(Mid[i]);
                temp = i;
            }
        }
    }
    for (int i = 0;i<l0.length();i++){
        if (l1.find(l0[i]) != l1.npos){
            cout<<l0[i]<<endl;
            return 0;
        }
    }

    cout<<"NULL"<<endl;
    return 0;
}
