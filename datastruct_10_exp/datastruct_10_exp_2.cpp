#include <iostream>
#include <string>
#include <malloc.h>

using namespace std;

typedef struct Node{
    char data;
    struct Node * LChild;
    struct Node * RChild;
}BiTNode, * BiTree;

void BuildTree(string Pre, string Post, BiTree Root){
    for (int i = 0; i < Pre.length(); ++i) {
        
    }
}

int main(){
    string Pre, Post;
    BiTree Root;
    Root = (BiTNode*)malloc(sizeof(BiTNode));
    cin>>Pre>>Post;

    return 0;
}
