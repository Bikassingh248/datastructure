#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode(int data){
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* insertNode(struct Node *root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}
void inOrderTraversal(struct Node *root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}
void displayInOrderTraversal(struct Node *root){
    if(root == NULL){
        printf("Tree is empty");
    }else{
        printf("In order traversal: ");
        inOrderTraversal(root);
        printf("\n");
    }
}
int main(){
    struct Node *root = NULL;
    int numNodes, data;
    printf("Enter number of nodes in binary search tree: ");
    scanf("%d", &numNodes);
    printf("Enter the values for each node: ");
    for(int i = 0; i < numNodes; i++){
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    displayInOrderTraversal(root);
    return 0;
}