#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data){
    struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void preorder(struct node* root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
} 
void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int isBST(struct node* root)
{
    static struct node* prev = NULL;
    if (root)
    {
        if (!isBST(root->left))
            return 0;
        if (prev && root->data <= prev->data)
            return 0;
        prev = root;
        return isBST(root->right);
    }
    return 1;
}
struct nod* search(struct node* root, int key){
    if(root==NULL || root->data==key)
        return root;
    if(key<root->data)
        return search(root->left,key);
    return search(root->right,key);
}
int main(){
    struct node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);

    printf("Preorder traversal: ");

    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    if (isBST(root))
        printf("The tree is a BST\n");
    else
        printf("The tree is not a BST\n");
    struct node* foundNode = search(root, 6);
    if (foundNode != NULL)
        printf("Found node with value %d\n", foundNode->data);
    else
        printf("Node not found\n");
    return 0;

}
