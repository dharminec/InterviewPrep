#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}Node;

Node * Newnode(int data)
{
    Node * temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insert(Node **head, int data)
{
    Node *node  =Newnode(data);
    node ->next = *head;
    *head = node;
}

void printList(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void deletkey(Node **head,int key)
{
    Node *temp = *head;
    Node *prev = NULL;
    if(*head == NULL)
        return;
    if((*head)->data == key)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    while(temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void deletNode(Node **head,Node *nodeLocation)
{
    Node *temp = *head;
    Node *prev = NULL;
    if(*head == NULL || nodeLocation == NULL)
        return;
    if((*head)== nodeLocation)
    {
        *head = (*head)->next;
        free(temp);
        return;
    }
    while(temp->next != nodeLocation)
    {
        temp = temp->next;
        if(temp == NULL) return;
    }
    prev = temp->next;
    temp->next = temp->next->next;
    free(prev);
}

int main()
{
    Node *head = NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);

 //   printList(head);

 //   deletkey(&head,10);
    deletNode(&head,head->next->next->next->next);
    printList(head);
    return 0;
}



