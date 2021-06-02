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

bool isPalindrome(ListNode* head)
{
    // Use 'slow' and 'fast' pointers to traverse the list.
    // When 'fast' pointer becomes nullptr, that means the 'slow' pointer is at the middle of the list.
    // While traversing, keep reversing the list with the help of 'slow' pointer.
    // We keep reversing the list until 'fast' reaches the end. When the 'fast' is at the end, then 'slow'
    // pointer is ready with the list reversed to traverse backward.

    if (nullptr == head || head->next == nullptr) return true;

    int len = 1;
    ListNode *slow = head, *fast = head;
    ListNode *prev = nullptr, *curr = head, *nxt = nullptr;
    while (nullptr != fast)
    {
        if (nullptr != fast->next)
        {
            ++len;
            if (nullptr != fast->next->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                ++len;

                // Keep reversing the list using slow pointer.
                curr->next = prev;
                prev = curr;
                curr = slow;

                continue;
            }
            if (len % 2 == 0)
            {
                nxt = curr->next;
                curr->next = prev;
            }
        }
        if (len % 2 != 0)
        {
            nxt = curr->next;
            curr->next = prev;
        }
        break;
    }

    if (len % 2 != 0)
    {
        curr = curr->next;
    }

    // 'curr' pointer is the start of reversed list from the center.
    // 'nxt' pointer is the start of the forward list from the center.
    while (curr != nullptr)
    {
        if (curr->val != nxt->val)
        {
            return false;
        }
        curr = curr->next;
        nxt = nxt->next;
    }
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(1);
    print(head);
    cout<< boolalpha << isPalindrome(head) << endl;
    return 0;
}
