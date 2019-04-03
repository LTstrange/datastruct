#include<iostream>
#include<malloc.h>
#include <iomanip>
using namespace std;

typedef struct Node{
    int exp;
    float coef;
    Node* next;
}Node, *LinkList;

void InitList(LinkList &L){
    L = (LinkList)malloc(sizeof(Node));
    L->next = NULL;
}

void show(LinkList L){
    while (L->next != NULL){
        cout<<"coef:"<<L->next->coef<<",exp:"<<L->next->exp<<endl;
        L= L->next;
    }
}

void CreateFromTail(LinkList L){
    int count=0;
    cin>>count;
    L->coef = count;
    Node *s;
    float c;
    int e;
    for (int i=0;i<count;i++){
        cin>>c>>e;
        s = (LinkList)malloc(sizeof(Node));
        s->coef = c;
        s->exp = e;
        s->next = NULL;
        L->next = s;
        L = s;
    }
}

LinkList merge(LinkList A, LinkList B){
    float countA, countB;
    LinkList C;
    InitList(C);
    countA = A->coef;
    countB = B->coef;
    C->coef = countA + countB;
    LinkList s, L;
    L = C;
    float c;
    int e;
    for (int i=0;i<countA;i++){
        c = A->next->coef;
        e = A->next->exp;
        s = (LinkList)malloc(sizeof(Node));
        s->coef = c;
        s->exp = e;
        s->next = NULL;
        L->next = s;
        L = s;
        A = A->next;
    }
    for (int i=0;i<countB;i++){
        c = B->next->coef;
        e = B->next->exp;
        s = (LinkList)malloc(sizeof(Node));
        s->coef = c;
        s->exp = e;
        s->next = NULL;
        L->next = s;
        L = s;
        B = B->next;
    }
    return C;
}

LinkList Clean(LinkList L){
//    cout<<L->coef<<endl;
    int Te;
    float Tc;
    for (LinkList i=L->next;i->next!=NULL;i=i->next){
        for (LinkList j=i->next;j!=NULL;j=j->next){
            if (i->exp < j->exp){
                Tc = i->coef;
                i->coef = j->coef;
                j->coef = Tc;
                Te = i->exp;
                i->exp = j->exp;
                j->exp = Te;
            }
        }
    }
//    cout<<"switch:"<<endl;
//    show(L);
    LinkList p=L->next, s;
    while(p->next!=NULL){
        while (p->exp == p->next->exp){
            p->coef += p->next->coef;
            s = p->next;
            if (s->next != NULL){
                p->next = s->next;
                free(s);
            }
            else{
                p->next=NULL;
                free(s);
                break;
            }
        }
        if (p->next != NULL)
            p = p->next;
    }
//    cout<<"rmsame:"<<endl;
//    show(L);
    p = L;
    while (p->next!=NULL){
        if (p->next->coef == 0){
            s = p->next;
            if (s->next != NULL){
                p->next = s->next;
                free(s);
            }
            else{
                p->next=NULL;
                free(s);
                break;
            }
        }
        if (p->next != NULL)
            p=p->next;
    }
    return L;
}

void find(int ind, LinkList L){
    for (int i=0;i<ind;i++){
        L = L->next;
    }
    cout<<fixed<<setprecision(1)<<L->coef<<' '<<dec<<L->exp;
}

int main(){
    LinkList A, B, C;
    InitList(A);
    InitList(B);
    CreateFromTail(A);
    CreateFromTail(B);
    C = merge(A, B);
//    show(C);
    C = Clean(C);
//    cout<<"main:"<<endl;
//    show(C);
    int i=0;
    cin>>i;
    find(i, C);
    return 0;
}
/*
2 -1 -1 -2 -2
5 -3 -3 1 1 2 2 1 -1 4 4

4 1.2 0 2.5 1 3.2 3 -2.5 5
5 -1.2 0 2.5 1 3.2 3 2.5 5 5.4 10
 */
