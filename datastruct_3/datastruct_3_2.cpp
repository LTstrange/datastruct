#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node, *LinkList;

void InitList(LinkList *L){
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void CreateFromTail(int count, LinkList L){
    Node *s;
    int i=0;
    while(count&&i!=EOF){
        scanf("%d", &i);
        s = (LinkList)malloc(sizeof(Node));
        s->data = i;
        L->next = s;
        L = s;
        count--;
    }
}

void show(LinkList L){
    LinkList s = L;
    while (s->next){
        printf("%d ", s->next->data);
        s = s->next;
    }
}

LinkList Merge(LinkList LA, LinkList LB){
    LinkList pa, pb, pc;
    LinkList LC, r, s;
    pa = LA->next;
    pb = LB->next;
    LC = LA;
    LC->next=NULL;r=LC;
    while (pa != NULL && pb != NULL){
        if (pa->data <= pb->data){
            r->next=pa;
            r = pa;
            pa = pa->next;
        }
        else{
            r->next = pb;
            r = pb;
            pb = pb->next;
        }
    }
    if (pa)
        r->next=pa;
    else
        r->next=pb;
    free(LB);
    pc = LC->next;
    int flag = 0;
    while(pc && pc->next)
    {
        flag=0;
        if(pc->data == pc->next->data)
        {
            s = pc->next;
            pc->next = s->next;
            flag = 1;
        }
        if(!flag)
            pc = pc->next;
    }
    return LC;
}

int main(){
    int i=0;
    LinkList LA, LB, LC;
    InitList(&LA);
    InitList(&LB);
    scanf("%d", &i);
    CreateFromTail(i, LA);
    scanf("%d", &i);
    CreateFromTail(i, LB);
    LC = Merge(LA, LB);
    show(LC);
    return 0;
}

