#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2

typedef struct 
{
    char name[100];
}Name;

typedef struct 
{
    Name* name;
    int length;
    int ListSize;
}SqList;

int InitList(SqList *L)
{
    (*L).name = (Name*)malloc(LIST_INIT_SIZE* sizeof(Name));
    if (!(*L).name)
        exit(OVERFLOW);
    (*L).length = 0;
    (*L).ListSize = LIST_INIT_SIZE;
    return 1;
}

int ListInsert(SqList *L, int i, Name e)
{
    Name *newbase, *q, *p;
    if (i < 1 || i > (*L).length + 1)
        return 0;
    if ((*L).length >= (*L).ListSize)
    {
        newbase = (Name*)realloc((*L).name, ((*L).ListSize + LISTINCREMENT) * sizeof(Name));
        if (!newbase)
            exit(OVERFLOW);
        (*L).name = newbase;
        (*L).ListSize += LISTINCREMENT;
    }
    q = (*L).name + i -1;
    for(p = (*L).name + (*L).length - 1; p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    ++(*L).length;
    return 1;
}

int ListDelete(SqList *L, int i, Name *e)
{
    Name *p, *q;
    if(i < 1 || i > (*L).length)
        return 0;
    p = (*L).name + i - 1;
    *e = *p;
    q = (*L).name + (*L).length - 1;
    for(++p; p <= q; ++p)
        *(p - 1) = *p;
    (*L).length--;
    return 1;
}

// 后面不太会写了。。。。还没有看懂
int LocateElem(SqList L,Name e,int(*compare)(Name, Name))
{
    Name *p;
    int i=1;
    p=L.name;
    while(i<=L.length&&!compare(*p++,e))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

void ListShow(SqList L)
{
    int i;
    for(i = 0; i<L.length; i++)
    {
        if(i)
            printf(" ");
        printf("%s",L.name[i].name);
    }
    printf("\n");
}

int cmp(Name e1,Name e2)
{
    return (int)!strcmp(e1.name,e2.name);
}
int main()
{
    SqList namelist;
    InitList(&namelist);
    char strInstruct[10];
    int pos;
    Name e;

    while(~scanf("%s",strInstruct))
    {
        if(!strcmp(strInstruct,"insert"))
        {
            scanf("%d%s",&pos,e.name);
            ListInsert(&namelist,pos,e);
        }
        else if(!strcmp(strInstruct,"show"))
        {
            ListShow(namelist);
        }
        else if(!strcmp(strInstruct,"delete"))
        {
            scanf("%s",e.name);
            pos = LocateElem(namelist,e,cmp);
            ListDelete(&namelist,pos,&e);
        }
        else if(!strcmp(strInstruct,"search"))
        {
            scanf("%s",e.name);
            printf("%d\n",LocateElem(namelist,e,cmp));
        }
    }
    return 0;
}
