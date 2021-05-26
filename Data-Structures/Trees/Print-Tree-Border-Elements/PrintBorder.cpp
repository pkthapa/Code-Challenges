/*
                                           100
                                        /       \
                                      50         150
                                     /  \       /   \
                                  30     70    130   200
                                 /  \   /  \    \    /  \
                                10  40 65  80   140 160 210
                                      / \
                                     60 68
                                     /
                                    55

Print border elements of the above tree.
Output: 100 50 30 10 40 55 68 80 140 160 210 200 150
*/

#include <iostream>
using namespace std;

class BST
{
public:
	int m_data;
	BST *left, *right;
	BST(int data = 0)
	{
		m_data = data;
		left = right = nullptr;
	}
};

bool isLeaf(BST *root)
{
	return (root->left == nullptr) && (root->right == nullptr);
}

void printLeaf(BST *root)
{
	if (nullptr != root)
	{
		printLeaf(root->left);
		printLeaf(root->right);

		if (isLeaf(root))
		{
			cout << root->m_data << " ";
		}
	}
}

void printLeft(BST *root)
{
	if (nullptr == root)
	{
		return;
	}

	if (!isLeaf(root))
	{
		cout << root->m_data << " ";
	}
	if (root->left != nullptr)
	{
		printLeft(root->left);
	}
	else if (root->right != nullptr)
	{
		printLeft(root->right);
	}
}

void printRight(BST *root)
{
	if (nullptr == root)
	{
		return;
	}

	if (root->right != nullptr)
	{
		printRight(root->right);
	}
	else if (root->left != nullptr)
	{
		printRight(root->left);
	}

	if (!isLeaf(root))
	{
		cout << root->m_data << " ";
	}
}

void printBorder(BST *root)
{
	if (nullptr != root)
	{   // Since the printing order is anti-clockwise, hence process left children, then leaf nodes, then right children.
		printLeft(root);
		printLeaf(root);
		printRight(root);
	}
}

int main()
{
	BST *root = new BST(100);
	root->left = new BST(50);
	root->left->right = new BST(70);
	root->left->left = new BST(30);
	root->left->left->left = new BST(10);
	root->left->left->right = new BST(40);
	root->left->right->left = new BST(65);
	root->left->right->left->left = new BST(60);
	root->left->right->left->left->left = new BST(55);
	root->left->right->left->right = new BST(68);
	root->left->right->right = new BST(80);
	root->right = new BST(150);
	root->right->right = new BST(200);
	root->right->right->right = new BST(210);
	root->right->right->left = new BST(160);
	root->right->left = new BST(130);
	root->right->left->right = new BST(140);

	printBorder(root);

	return 0;
}