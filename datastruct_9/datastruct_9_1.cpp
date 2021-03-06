#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stack>

using namespace std;


typedef struct Node{
    char data;
    struct Node * LChild;
    struct Node * RChild;
}BiTNode, * BiTree;

void BuildTree(BiTree &root){
    char ch;
    root = (Node*)malloc(sizeof(Node));
    ch = getchar();
    if (ch != '#'){
        root->data = ch;
        BuildTree(root->LChild);
        BuildTree(root->RChild);
    } else {
        root = NULL;
    }
}

void PrePrint(BiTree root){
    if (root != NULL){
        stack<BiTree >stk;
        stk.push(root);
        BiTree cur;
        while (!stk.empty()){
            cur = stk.top();
            stk.pop();
            cout<<cur->data<<' ';
            if (cur->RChild != NULL) stk.push(cur->RChild);
            if (cur->LChild != NULL) stk.push(cur->LChild);
        }
    }
    cout<<endl;
}

void MidPrint(BiTree root){
    stack<BiTree >stk;
    BiTree p = root;
    while (p!= NULL || !stk.empty()){
        if (p != NULL){
            stk.push(p);
            p = p->LChild;
        } else {
            p = stk.top();
            stk.pop();
            cout<<p->data<<' ';
            p = p->RChild;
        }
    }
    cout<<endl;
}

void PostPrint(BiTree root){
    if (root->LChild){
        PostPrint(root->LChild);
    }
    if (root->RChild){
        PostPrint(root->RChild);
    }
    cout<<root->data<<' ';

}

//void PostPrint(BiTree root){
//    stack<BiTree >stk;
//    BiTree p = root, pre;
//    while (p!= NULL || !stk.empty()){
//        while (p != NULL){
//            stk.push(p);
//            p = p->LChild;
//        }
//        p = stk.top();
//        if (p->LChild == NULL && p->RChild == NULL){
//            cout<<p->data<<' ';
//            do {
//                pre = p;
//                stk.pop();
//                p = stk.top();
//                if (pre == p->RChild){
//                    cout<<p->data<<' ';
//                }
//            }while (pre == p->RChild);
//            p = stk.top();
//            p = p->RChild;
//        } else {
//            if (p->RChild == NULL){
//                cout<<p->data<<' ';
//                stk.pop();
//                break;
//            }
//            p = p->RChild;
//        }
//    }
//    cout<<endl;
//}

int main(){
    BiTree root;
    BuildTree(root);
    PrePrint(root);
    MidPrint(root);
    PostPrint(root);
    return 0;
}

