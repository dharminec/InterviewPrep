#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}BST;

BST *newnode(int data)
{
        BST *node = (BST *)malloc(sizeof(BST));
        node->data = data;
        node->right = NULL;
        node ->left = NULL;
        return node;
}

BST *insert(BST *head, int data)
{
    if(head==NULL)
    {
        BST *node  = newnode(data);
        head = node;
        return head;
    }

    if(data < head->data)
        head->left = insert(head->left,data);
    else
        head->right = insert(head->right,data);
    return head;
}

BST * MinNode(BST *head)
{
     while(head->left != NULL)
         head = head->left;
     return head;
}

BST * delet(BST *head,int data)
{
    if(head==NULL) return NULL;
    else if(data < head->data ) head ->left = delet(head->left, data);
    else if(data > head->data ) head ->right = delet(head->right, data);
    else
    {
        if(head->left==NULL && head->right==NULL)
        {
            free(head);
            head = NULL;
            return head;
        }
        else if(head->right == NULL)
        {
            BST *temp = head;
            head = head->left;
            free(temp);
            return head;
        }
        else if(head->left == NULL)
        {
            BST *temp = head;
            head = head->right;
            free(temp);
            return head;
        }
        else
        {
            BST *temp = MinNode(head->right);
            head->data  = temp->data;
            head->right = delet (head->right, head->data);
        }
    }
    return head;
}

void printInorder(BST *head)
{
   if(head ==NULL) return;
    printInorder(head->left);
    printf("%d--",head->data);
    printInorder(head->right);
}

void printPreorder(BST *head)
{
   if(head ==NULL) return;
   printf("%d--",head->data);
   printPreorder(head->left);
   printPreorder(head->right);
}

void printPostorder(BST *head)
{
   if(head ==NULL) return;
   printPreorder(head->left);
   printPreorder(head->right);
   printf("%d ",head->data);
}

//Function to visit nodes in Preorder
void Preorder(BST *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) return;

	printf("%c ",root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder
void Inorder(BST *root) {
	if(root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%c ",root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(BST *root) {
	if(root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%c ",root->data); // Print data
}

int NumberofNodes(BST *root)
{
    if(root == NULL)
        return 0;

    return 1 + NumberofNodes(root->right) + NumberofNodes(root->left);
}

int HightofTree(BST *root)
{
    if(root == NULL)
        return 0;

    int left = HightofTree(root->left);
    int right = HightofTree(root->right);

    if(left > right)
        return 1 + left;
    return 1 + right;
}




int main()
{
    BST *head = NULL;
    head = insert(head,10);
    head = insert(head,20);
    head = insert(head,40);
    head = insert(head,60);
    head = insert(head,15);
    head = insert(head,5);

  //  Preorder(head);

    head = delet(head, 40);
    head = insert(head,20);
    head = delet(head, 7);
    head = delet(head, 20);

    printf("\n");
    printPostorder(head);

    printf("\n%d =  Numberof Node", NumberofNodes(head));
    printf("\n%d =  Hight of tree", HightofTree(head));
    return 0;
}


