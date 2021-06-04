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

ListNode* shiftNegatives(ListNode* head)
{
    if (nullptr == head || nullptr == (head)->next) return head;

    bool isPositive = true, isNegative = true;
    ListNode* pEnd = head;
    while (pEnd->next != nullptr)
    {
        if (pEnd->val < 0)
        {
            isPositive = false;
        }
        else if (pEnd->val >= 0)
        {
            isNegative = false;
        }
        pEnd = pEnd->next;
    }
    // pEnd points to the last node.

    if (isPositive || isNegative) return head;

    ListNode* pEndBackup = pEnd;

    // If the start elements are negative, then shift all to the end.
    while (head->val < 0)
    {
        pEnd->next = head;
        pEnd = head;
        head = head->next;
        pEnd->next = nullptr;
    }

    // Shift all negative elements from the middle to the end.
    ListNode* p1 = head, *p2 = head->next;
    while (p2 != pEndBackup)
    {
        if (p2->val < 0)
        {
            p1->next = p2->next;
            p2->next = pEnd->next;
            pEnd->next = p2;
            pEnd = p2;
            p2 = p1->next;
        }
        else
        {
            p1 = p2;
            p2 = p2->next;
        }
    }

    // If pEndBackup is negative, then shift it to the last of the list.
    if (pEndBackup->val < 0)
    {
        p1->next = p2->next;
        p2->next = pEnd->next;
        pEnd->next = p2;
        pEnd = p2;
        p2 = p1->next;
    }
    return head;
}

int main()
{
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(-5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    print(head);

    head = shiftNegatives(head);
    print(head);

    return 0;
}
/*
Output:
-1 2 -3 4 -5 6 7
2 4 6 7 -1 -3 -5
*/