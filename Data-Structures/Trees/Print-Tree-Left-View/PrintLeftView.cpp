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

Print left view elements of the above tree.
Output: 100 50 30 10 60 55
*/
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

void printLeftView(BST *root)
{
	if (nullptr == root)
	{
		return;
	}

    // Do level-order traversal. Print the first element of the height when traversing.
	queue<BST *> q;
	q.push(root);

	while (!q.empty())
	{
		int n = q.size();

		for (int i = 1; i <= n; ++i)
		{
			BST *temp = q.front();
			q.pop();

			if (i == 1) // Print the first element (left most element) at the level.
			{
				cout << temp->m_data << " ";
			}

			if (temp->left != nullptr)
			{
				q.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				q.push(temp->right);
			}
		}
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

	printLeftView(root);

	return 0;
}