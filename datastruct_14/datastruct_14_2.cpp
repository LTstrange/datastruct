#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    Node *Lchild;
    Node *Rchild;
} *BinTree;

void Insert(BinTree root, int data) {
    if (!root->data) {
        root->data = data;
    } else {
        if (data > root->data) {
            if (root->Rchild == NULL) {
                root->Rchild = (BinTree) malloc(sizeof(Node));
            }
            Insert(root->Rchild, data);
        } else {
            if (root->Lchild == NULL) {
                root->Lchild = (BinTree) malloc(sizeof(Node));
            }
            Insert(root->Lchild, data);
        }
    }
}

void Delete(BinTree root, int target) {
    if (root->data == target)
    {

    }
}

int main() {
    int x;
    BinTree root;
    root = (BinTree)malloc(sizeof(Node));

    while (cin >> x) {
        if (!x) break;
        Insert(root, x);
    }

    int target, finddata;

    cin>>target>>finddata;

    return 0;
}