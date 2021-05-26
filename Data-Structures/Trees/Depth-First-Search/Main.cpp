#include <bits/stdc++.h>
#include "DFS.h"
/*
                                     40
                                    /  \
                                  50    60
                                 /  \   / \
                               100  30 3  200
                               / \         / \
                              4  20      400  1
                                             / \
                                            11 33
                                                 \
                                                 22
                                                 /
                                                19
                                                 \
                                                 29
*/
int main ()
{
    clock_t start = clock();
    DFS *root = new DFS(40);
    root->left = new DFS(50);
    root->left->left = new DFS(100);
    root->left->right = new DFS(30);
    root->left->left->left = new DFS(4);
    root->left->left->right = new DFS(20);

    root->right = new DFS(60);
    root->right->left = new DFS(3);
    root->right->right = new DFS(200);
    root->right->right->left = new DFS(400);
    root->right->right->right = new DFS(1);
    root->right->right->right->left = new DFS(11);
    root->right->right->right->right = new DFS(33);
    root->right->right->right->right->right = new DFS(22);
    root->right->right->right->right->right->left = new DFS(19);
    root->right->right->right->right->right->left->right = new DFS(29);

    DFS d;
    std::cout << "Depth: " << d.depth(root) << std::endl;
    d.traverse(root);
    d.findData(root, 100);
    std::cout << "Elapsed time: " << (double)(clock() - start)/(double)CLOCKS_PER_SEC << " secs." << std::endl;
    return 0;
}
