#include "BFS.h"
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
int main()
{
    clock_t start = clock();
    BFS *root = new BFS(40);
    root->left = new BFS(50);
    root->left->left = new BFS(100);
    root->left->right = new BFS(30);
    root->left->left->left = new BFS(4);
    root->left->left->right = new BFS(20);

    root->right = new BFS(60);
    root->right->left = new BFS(3);
    root->right->right = new BFS(200);
    root->right->right->left = new BFS(400);
    root->right->right->right = new BFS(1);
    root->right->right->right->left = new BFS(11);
    root->right->right->right->right = new BFS(33);
    root->right->right->right->right->right = new BFS(22);
    root->right->right->right->right->right->left = new BFS(19);
    root->right->right->right->right->right->left->right = new BFS(29);

    BFS d;
    std::cout << "Depth: " << d.depth(root) << std::endl;
    d.traverse(root);
    d.findData(root, 100);
    std::cout << "Elapsed time: " << (double)(clock() - start)/(double)CLOCKS_PER_SEC << " secs." << std::endl;
    return 0;
}
