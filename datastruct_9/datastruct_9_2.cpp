#include <iostream>
#include <string>

using namespace std;

typedef struct Node {
    char data;
    struct Node *LChild;
    struct Node *RChild;
} BiTNode, *BiTree;

void BuildTree(BiTree &root) {
    char ch;
    root = (Node *) malloc(sizeof(Node));
    ch = getchar();
    if (ch != '#') {
        root->data = ch;
        BuildTree(root->LChild);
        BuildTree(root->RChild);
    } else {
        root = NULL;
    }
}

void change_LRchild(BiTree &root, int &count) {
    if (!(root->LChild) && !(root->RChild)) {
        count++;
        return;
    }
    BiTree temp;
    temp = root->RChild;
    root->RChild = root->LChild;
    root->LChild = temp;
    if(root->RChild)
    change_LRchild(root->RChild, count);
    if(root->LChild)
    change_LRchild(root->LChild, count);
}

void print(BiTree &root){
    if (root){
        print(root->LChild);
        print(root->RChild);
        cout<<root->data;
    } else{
        cout<<'#';
    }
}

int main() {
    BiTree root;
    int count = 0;
    BuildTree(root);

    change_LRchild(root, count);

    cout<<count<<endl;

    print(root);

    return 0;
}
