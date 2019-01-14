#include "main.h"
using namespace std;
class BST{
    int data;
    BST *left, *right;
public:
    BST() : data(0), left(NULL), right(NULL){}
    BST(int n){
        data = n;
        left = right = NULL;
    }
    void PreOrder(BST *);
    void InOrder(BST *);
    void PostOrder(BST *);
    int MaxDepth(BST *);
    void CreateMirror(BST *);
    void PrintLevelOrder(BST *);//!! BFS traversal.
    void PrintBFS(BST *, int);//!! BFS printing during traversing.
	BST *Insert(BST *, int);
};
//-----------
BST *BST :: Insert(BST *node, int value)
{
	if(!node){
		return new BST(value);
	}

	if(value < node->data){
		node->left = Insert(node->left, value);
	}
	else{
		node->right = Insert(node->right, value);
	}
	return node;
}

void BST :: PreOrder(BST *node){
    if(!node){
        return;
    }

	cout<<node->data<<" ";
	PreOrder(node->left);
	PreOrder(node->right);
}

void BST :: PostOrder(BST *node){
    if(!node){
        return;
    }

	PostOrder(node->left);
	PostOrder(node->right);
	cout<<node->data<<" ";
}

void BST :: InOrder(BST *node){
    if(!node){
        return;
    }

	InOrder(node->left);
	cout<<node->data<<" ";
	InOrder(node->right);
}

int BST :: MaxDepth(BST *node){
    if(!node){
        return 0;
    }
    int ldepth = 0, rdepth = 0;
    return ((((ldepth = MaxDepth(node->left)) > (rdepth = MaxDepth(node->right))) ? (ldepth + 1) : (rdepth + 1)));
}

void BST :: CreateMirror(BST *node){
    if(!node){
        return;
    }
    BST *temp = node->left;
    node->left = node->right;
    node->right = temp;

    CreateMirror(node->left);
    CreateMirror(node->right);
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
        PrintBFS(node->right, level - 1);
        PrintBFS(node->left, level - 1);
    }
}

int main()
{
    BST *root = NULL, o;
    /*root = new BST(20);
    root->right = new BST(30);
    root->left = new BST(10);
    root->left->left = new BST(9);
    root->left->right = new BST(14);
    root->left->right->left = new BST(11);
    root->left->right->right = new BST(16);
    root->left->right->right->left = new BST(15);
    root->right->left = new BST(21);
    root->right->right = new BST(40);*/
	root = o.Insert(root, 60);
	o.Insert(root, 10);
	o.Insert(root, 5);
	o.Insert(root, 30);
	o.Insert(root, 40);
	o.Insert(root, 70);
	o.Insert(root, 25);
	o.Insert(root, 23);
	o.Insert(root, 88);

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