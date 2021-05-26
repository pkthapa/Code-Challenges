#include <bits/stdc++.h>

class BFS
{
    int data;
public:
    BFS *left, *right;
    BFS();
    BFS(const int);
    int depth(BFS *);
    void traverse(BFS *);
    bool findData(BFS *, const int);
};

BFS::BFS()
{}

BFS::BFS(const int data)
{
    this->data = data;
    this->left = this->right = nullptr;
}

int BFS::depth(BFS *root)
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

void BFS::traverse(BFS *root)
{
    if(nullptr == root)
    {
        std::cout << "Tree is empty!" << std::endl;
    }
    else
    {
        BFS *temp = nullptr;
        std::queue<BFS *> que;
        que.push(root);
        std::cout << "BFS tree data: ";
        while(!que.empty())
        {
            temp = que.front();
            std::cout << temp->data << " ";
            que.pop();

            if(nullptr != temp->left)
            {
                que.push(temp->left);
            }

            if(nullptr != temp->right)
            {
                que.push(temp->right);
            }
        }
        std::cout << std::endl;
    }
}

bool BFS::findData(BFS *root, const int data)
{
    bool ret = false;
    if(nullptr == root)
    {
        std::cout << "Tree is empty!" << std::endl;
    }
    else
    {
        BFS *temp = nullptr;
        std::queue<BFS *> que;
        que.push(root);
        int counter = 0;
        bool found = false;
        while(!que.empty())
        {
            counter++;
            temp = que.front();

            if(data == temp->data)
            {
                std::cout << "Data found: " << data << ", after iterations: " << counter << std::endl;
                found = true;
                break;
            }

            que.pop();

            if(nullptr != temp->left)
            {
                que.push(temp->left);
            }

            if(nullptr != temp->right)
            {
                que.push(temp->right);
            }
        }

        if(!found)
        {
            std::cout << "Data not found: " << data << ", after iterations: " << counter << std::endl;
        }
    }
    return ret;
}
