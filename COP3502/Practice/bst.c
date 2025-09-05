#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int data;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createTreeNode(int val)
{
    treenode *t = (treenode *)malloc(sizeof(treenode));
    t->data = val;
    t->left = NULL;
    t->right = NULL;
    return t;
}

treenode *insertToTree(treenode *root, treenode *node)
{
    if (!root)
        return node;
    else
    {
        if (node->data > root->data)
        {
            if (root->right)
                root->right = insertToTree(root->right, node);
            else
                root->right = node;
        }
        else
        {
            if (root->left)
                root->left = insertToTree(root->left, node);
            else
                root->left = node;
        }
    }
}

void preorder(treenode *root)
{
    if (root)
    {
        printf("%d, ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(treenode *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

void postorder(treenode *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d, ", root->data);
    }
}

int minVal(treenode *root)
{
    if (!root->left)
        return root->data;
    return minVal(root->left);
}

int numLeafNodes(treenode *root)
{
    if (root)
    {
        if (!root->left && !root->right)
            return 1;
        return numLeafNodes(root->left) + numLeafNodes(root->right);
    }
    else
        return 0;
}

// int sumNonLeafOdd(treenode* root)
// {
//     int val;
//     if (!root) return 0;
//     val = root->data;
//     if (val % 2 == 0 || (!root->left && !root->right))
//         return sumNonLeafOdd(root->left) + sumNonLeafOdd(root->right);
//     else
//         return val + sumNonLeafOdd(root->left) + sumNonLeafOdd(root->right);
// }

int sumNonLeafOdd(treenode *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 0;

    int val = root->data;
    if (val % 2 != 0)
        return val + sumNonLeafOdd(root->left) + sumNonLeafOdd(root->right);
    else
        return sumNonLeafOdd(root->left) + sumNonLeafOdd(root->right);
}

// int height(treenode *root)
// {
//     if (!root)
//         return 0;

//     int lh = height(root->left);
//     int rh = height(root->right);

//     if (lh > rh)
//         return 1 + lh;

//     return 1 + rh;
// }

int height(treenode *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh > rh)
        return lh + 1;
    return rh + 1;
}

int foo(treenode *root)
{
    if (root == NULL)
        return 1;
    if (root->left == NULL && root->right == NULL)
        return 2;
    if (root->left == NULL)
        return 3 * foo(root->right);
    if (root->right == NULL)
        return 4 * foo(root->left);
    if (root->right->data > root->left->data)
        return 5 * foo(root->right);
    return 6 * foo(root->left);
}

int foo_iter(treenode *root)
{
    int result = 1;
    treenode *temp = root;
    while (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            result *= 2;
            temp = NULL;
        }
        else if (temp->left == NULL)
        {
            result *= 3;
            temp = temp->right;
        }
        else if (temp->right == NULL)
        {
            result *= 4;
            temp = temp->left;
        }
        else if (temp->right->data > temp->left->data)
        {
            result *= 5;
            temp = temp->right;
        }
        else
        {
            result *= 6;
            temp = temp->left;
        }
    }
    return result;
}

int legacyHelper(treenode *root, int minAncestor)
{
    if (!root)
        return 0;

    if (root->data > minAncestor)
        return 1 + legacyHelper(root->left, minAncestor) + legacyHelper(root->right, minAncestor);
    else
        return legacyHelper(root->left, root->data) + legacyHelper(root->right, root->data);
}

int legacyCount(treenode *root)
{
    if (root == NULL)
        return 0;
    return legacyHelper(root->left, root->data) +
           legacyHelper(root->right, root->data);
}

int findBelow(treenode *root, int val)
{
}

int main(void)
{
    // define numElements and create root and nodes
    int numElements;
    scanf("%d", &numElements);
    treenode *root = NULL, *node = NULL;

    // create tree
    for (int i = 0; i < numElements; i++)
    {
        int val;
        scanf("%d", &val);
        node = createTreeNode(val);
        root = insertToTree(root, node);
    }

    // order
    printf("predorder: ");
    preorder(root);
    printf("\n");

    printf("inorder: ");
    inorder(root);
    printf("\n");

    printf("postorder: ");
    postorder(root);
    printf("\n");

    // min val
    printf("minval: %d\n", minVal(root));

    // numleaf
    printf("numleaf: %d\n", numLeafNodes(root));

    // sum non leaf odd
    printf("sum non leaf odd: %d\n", sumNonLeafOdd(root));

    // height
    printf("height: %d\n", height(root));

    // foo_rec
    printf("foo_rec: %d\n", foo(root));

    // foo_iter
    printf("foo_iter: %d\n", foo_iter(root));

    // legacyCount
    printf("legacyCount: %d\n", legacyCount(root));
}