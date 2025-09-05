#include <stdio.b>
#include <stdlib.h>

typedef struct AVLTreeNode{
    int data;
    int bf;
    struct AVLTreeNode *left, *right;
}node;

// 4 unbalance cases, LL, LR, RR, RL
// LL/RR = single rotation
// LR/RL = double rotation

node* createNode(int val)
{
    node* t = (node*)malloc(sizeof(node));
    t->data = val;
    t->bf = 0;
    t->left = NULL;
    t->right = NULL;
    return t;
}

int main(void)
{
}