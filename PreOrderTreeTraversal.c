#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode *createNode(int data)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode *insertNode(struct TreeNode *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}
void preOrderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void displayPreOrderTraversal(struct TreeNode *root)
{
    if (root == NULL)
    {
        printf("Tree is empty");
    }
    else
    {
        printf("Pre order traversal: ");
        preOrderTraversal(root);
        printf("\n");
    }
}
int main()
{
    struct TreeNode *root = NULL;
    int numNodes, data;
    printf("Enter number of nodes in binary search tree: ");
    scanf("%d", &numNodes);
    printf("Enter the values for each node: ");
    for (int i = 0; i < numNodes; i++)
    {
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    displayPreOrderTraversal(root);
    return 0;
}
