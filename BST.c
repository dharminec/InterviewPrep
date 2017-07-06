#include <stdio.h>
#include <stdlib.h>

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


void print(BST *head)
{
   if(head ==NULL) return;
    print(head->left);
    printf("%d--",head->data);
    print(head->right);
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
    
    
    print(head);
    
    
    head = delet(head, 40);
    head = insert(head,20);
    head = delet(head, 5);
    head = delet(head, 20);
    
    printf("\n");
    print(head);
    return 0;
}


