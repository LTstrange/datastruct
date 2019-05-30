#include <iostream>
#include <malloc.h>

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
            if (!root->Rchild) {
                root->Rchild = (BinTree) malloc(sizeof(Node));
            }
            Insert(root->Rchild, data);
        } else {
            if (!root->Lchild) {
                root->Lchild = (BinTree) malloc(sizeof(Node));
            }
            Insert(root->Lchild, data);
        }
    }
}

void Delete(BinTree &root, int target) {
    BinTree p, f, s, q;
    p = root;
    f = NULL;
    while (p) {
        if (p->data == target) break;
        f = p;
        if (p->data > target) p = p->Lchild;
        else p = p->Rchild;
    }
    if (!p) return;
    if (!p->Lchild) {
        if (!f) root = p->Rchild;
        else if (f->Lchild == p) f->Lchild = p->Rchild;
        else f->Rchild = p->Rchild;
        free(p);
    } else {
        q = p;
        s = p->Lchild;
        while (s->Rchild) {
            q = s;
            s = s->Rchild;
        }
        if (q == p) q->Lchild = s->Lchild;
        else q->Rchild = s->Lchild;
        p->data = s->data;
        free(s);
    }
}

void LDR(BinTree root) {
    if (root) {
        LDR(root->Lchild);
        cout << root->data << ' ';
        LDR(root->Rchild);
    }
}

void find(BinTree root, int finddata, int depth) {
    if (root->data == finddata){
        cout<<depth+1<<endl;
        return;
    }
    if (root->Rchild) find(root->Rchild, finddata, depth+1);
    if (root->Lchild) find(root->Lchild, finddata, depth+1);
}

int main() {
    int x;
    BinTree root;
    root = (BinTree) malloc(sizeof(Node));

    while (cin >> x) {
        if (!x) break;
        Insert(root, x);
    }

    int target, finddata;

    cin >> target >> finddata;

//    LDR(root);
//    cout<<endl;
    Delete(root, target);

    LDR(root);
    cout<<endl;

    find(root, finddata, 0);

    return 0;
}