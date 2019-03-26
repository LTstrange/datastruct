#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    struct Node* pre;
    int data;
    struct Node* next;
}Node, *LinkList;

void InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = *L;
    (*L)->pre = *L;
}

void CreateFromTail(int count, LinkList H){
    LinkList s, L;
    L = H;
    int i=0;
    while(count){
        scanf("%d", &i);
        s = (LinkList)malloc(sizeof(Node));
        s->data = i;
        s->pre = L;
        s->next = H;
        L->next = s;
        L = s;
        count--;
    }
}

void Sequence(int length, LinkList L){
    Node *s;
    s = L->next;
    int temp=0;
    while (s->data > s->next->data && s->next != L){
        temp = s->data;
        s->data = s->next->data;
        s->next->data = temp;
        s = s->next;
    }
}

void show(LinkList L){
    LinkList s = L->next;
    while (s != L){
        printf("%d ", s->data);
        s = s->next;
    }
}

int main(){
    int length;
    LinkList L;
    InitList(&L);
    scanf("%d", &length);
    CreateFromTail(length, L);
    Sequence(length, L);
    show(L);
    return 0;
}
