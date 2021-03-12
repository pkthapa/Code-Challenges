#include <iostream>
using namespace std;

class LL
{
    int m_data;
public:
    LL();
    LL(int);
    ~LL();
    LL *next;
    void print(LL *);
    void reverseList(LL **);
};

LL::LL(int data)
{
    m_data = data;
    next = nullptr;
}

LL::LL()
{
    //cout << "Object created." << endl;
}

LL::~LL()
{
    //cout << "Object destroyed." << endl;
}

void LL::print(LL *root)
{
    if (nullptr == root)
    {
        cout << "Empty list." << endl;
    }
    else
    {
        LL *temp = root;
        while (temp != nullptr)
        {
            cout << temp->m_data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void LL::reverseList(LL **root)
{
    if (nullptr == *root)
    {
        cout << "Empty list." << endl;
    }
    else
    {
        // Initialize three pointers.
        LL *curr = *root;
        LL *nextNode = nullptr;
        LL *prevNode = nullptr;
        while(curr != nullptr)
        {
            nextNode = curr->next; // Store next node info.
            curr->next = prevNode; // This is main logic of reversing.
            prevNode = curr; // Store current node as previous and then update current node with next node.
            curr = nextNode;
        }
        *root = prevNode;
    }
}

int main()
{
    LL *root = new LL(1);
    root->next = new LL(2);
    root->next->next = new LL(3);
    root->next->next->next = new LL(4);
    root->next->next->next->next = new LL(5);
    root->next->next->next->next->next = new LL(6);
    root->next->next->next->next->next->next = new LL(7);

    LL ll;
    ll.print(root);
    ll.reverseList(&root);
    ll.print(root);
    return 0;
}