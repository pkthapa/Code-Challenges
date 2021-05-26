#include <iostream>

class DFS
{
    int data;
public:
    DFS *left, *right;
    DFS();
    DFS(const int);
    int depth(DFS *);
    void traverse(DFS *);
    void findData(DFS *, const int);
};

DFS::DFS()
{
    this->data = 0;
    this->left = this->right = nullptr;
}

DFS::DFS(const int data)
{
    this->data = data;
    this->left = this->right = nullptr;
}

int DFS::depth(DFS *root)
{
    int d = 0;
    if(nullptr == root)
    {
        d = 0;
    }
    else
    {
        int ld = depth(root->left);
        int rd = depth(root->right);

        if(ld > rd)
        {
            d = ld + 1;
        }
        else
        {
            d = rd + 1;
        }
    }
    return d;
}

void DFS::traverse(DFS *root)
{
    if(nullptr == root)
    {
        std::cout << "Tree is empty." << std::endl;
    }
    else
    {
        std::stack<DFS *> st;
        DFS *temp = nullptr;
        st.push(root);

        std::cout << "DFS tree data: ";
        while(!st.empty())
        {
            temp = st.top();
            st.pop();
            std::cout << temp->data << " ";

            if(nullptr != temp->right)
            {
                st.push(temp->right);
            }

            if(nullptr != temp->left)
            {
                st.push(temp->left);
            }
        }
    }
}

void DFS::findData(DFS *root, const int searchData)
{
    std::cout << std::endl;
    if(nullptr == root)
    {
        std::cout << "Tree is empty." << std::endl;
    }
    else
    {
        bool found = false;
        int iteration = 0;
        std::stack<DFS *> st;
        DFS *temp = nullptr;
        st.push(root);
        while(!st.empty())
        {
            iteration++;
            temp = st.top();
            st.pop();

            if(searchData == temp->data)
            {
                std::cout << "Found: " << searchData << " after " << iteration << " iterations." << std::endl;
                found = true;
                break;
            }

            if(nullptr != temp->right)
            {
                st.push(temp->right);
            }

            if(nullptr != temp->left)
            {
                st.push(temp->left);
            }
        }

        if(!found)
        {
            std::cout << "Not found!" << std::endl;
        }
    }
}
