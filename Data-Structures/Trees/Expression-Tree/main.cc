#include "main.h"
#define unsigned int uint

class ET
{
public:
    char c;
    ET *left, *right;
    ET(const char c)
    {
        this->c = c;
        left = right = nullptr;
    }
};

bool isOperator(const char& c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
    {
        return true;
    }
    return false;
}

ET* newNode(const char c)
{
    return new ET(c);
}

ET* constructTreeFromPostfix(const char* input)
{
    uint len = strlen(input);
    stack<ET*> st;
    ET *temp = nullptr;
    char ch = '\0';

    for (uint i = 0; i < len; ++i)
    {
        ch = input[i];
        if (isOperator(ch))
        {
            temp = newNode(ch);

            temp->right = st.top();
            st.pop();

            temp->left = st.top();
            st.pop();

            st.push(temp);
        }
        else
        {
            st.push(newNode(ch));
        }
    }

    temp = st.top();
    st.pop();
    return temp;
}

void printInorder(const ET* head)
{
    if (nullptr != head)
    {
        printInorder(head->left);
        cout << head->c << " ";
        printInorder(head->right);
    }
}

int main()
{
    const char* c = "ab+ef*g*-";
    ET* head = constructTreeFromPostfix(c);
    printInorder(head);
    return 0;
}

