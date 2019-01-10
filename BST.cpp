#include "main.h"
using namespace std;
class BST{
    int data;
public:
    BST *prev, *next;
    BST() : data(0), prev(NULL), next(NULL){}
    BST(int n){
        data = n;
        prev = next = NULL;
    }
    void PreOrder(BST *);
    void InOrder(BST *);
    void PostOrder(BST *);
    int MaxDepth(BST *);
    void CreateMirror(BST *);
    void PrintLevelOrder(BST *);//!! BFS traversal.
    void PrintBFS(BST *, int);//!! BFS printing during traversing.
};
//-----------
void BST :: PreOrder(BST *node){
    if(!node){
        return;
    }
    if(node){
        cout<<node->data<<" ";
        PreOrder(node->prev);
        PreOrder(node->next);
    }
}

void BST :: PostOrder(BST *node){
    if(!node){
        return;
    }
    if(node){
        PostOrder(node->prev);
        PostOrder(node->next);
        cout<<node->data<<" ";
    }
}

void BST :: InOrder(BST *node){
    if(!node){
        return;
    }
    if(node){
        InOrder(node->prev);
        cout<<node->data<<" ";
        InOrder(node->next);
    }
}

int BST :: MaxDepth(BST *node){
    if(!node){
        return 0;
    }
    int ldepth = 0, rdepth = 0;
    return ((((ldepth = MaxDepth(node->prev)) > (rdepth = MaxDepth(node->next))) ? (ldepth + 1) : (rdepth + 1)));
}

void BST :: CreateMirror(BST *node){
    if(!node){
        return;
    }
    BST *temp = node->prev;
    node->prev = node->next;
    node->next = temp;

    CreateMirror(node->prev);
    CreateMirror(node->next);
}

void BST :: PrintLevelOrder(BST *node){
    int height = MaxDepth(node);

    for(int i = 1; i <= height; i++){
        PrintBFS(node, i);
    }
}

void BST :: PrintBFS(BST *node, int level){
    if(!node){
        return;
    }
    if(level == 1){
        cout<<node->data<<" ";
        return;
    }
    else if(level > 1){
        PrintBFS(node->next, level - 1);
        PrintBFS(node->prev, level - 1);
    }
}

int main()
{
    BST *root = NULL, o;
    root = new BST(20);
    root->next = new BST(30);
    root->prev = new BST(10);
    root->prev->prev = new BST(9);
    root->prev->next = new BST(14);
    root->prev->next->prev = new BST(11);
    root->prev->next->next = new BST(16);
    root->prev->next->next->prev = new BST(15);
    root->next->prev = new BST(21);
    root->next->next = new BST(40);

    cout<<"Pre-order traversal: ";
    o.PreOrder(root);
    cout<<"\n\nIn-order traversal: ";
    o.InOrder(root);
    cout<<"\n\nPost-order traversal: ";
    o.PostOrder(root);
    cout<<"\n\nDepth of BST = "<<o.MaxDepth(root);

    //!!---------------------------
    o.CreateMirror(root);
    cout<<"\n\nAfter mirror image, in-order traversal: ";
    o.InOrder(root);
    //!!---------------------------
    cout<<"\n\nBFS traversal: ";
    o.PrintLevelOrder(root);
    cout<<endl;
    return 0;
}
