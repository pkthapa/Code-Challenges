#include "main.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr){}
};

void print(ListNode* head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int findNodeFromLast(ListNode* head, int k)
{
    // Two pointer approach:
    // Increment only 'first' pointer 'k' times.
    // Then, increment both 'first' & 'second' pointers until 'first' pointer reaches the end.
    if (nullptr == head || k <= 0)
    {
        return -1;
    }

    ListNode *first = head, *second = head;
    while (first != nullptr)
    {
        first = first->next;

        if (k > 0)
        {
            --k;
            continue;
        }
        second = second->next;
    }
    return (k > 0) ? -1 : second->val;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    print(head);

    int n = 0;
    cout << "Position:";
    cin >> n;
    cout << findNodeFromLast(head, n) << endl;
    return 0;
}
/*
Output:
1 2 3 4 5 6 7
Position:2
6
*/