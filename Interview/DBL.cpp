#include <stdio.h>
#include <stdlib.h>


typedef struct linkedlist{
    int data;
    struct linkedlist *next;
    struct linkedlist *prev;
}DBL;


DBL * newnode(int data)
{
    DBL *temp = (DBL*)malloc(sizeof(DBL));
    temp->next = temp->prev = NULL;
    temp->data = data;
    return temp;
}

void insertInfront(DBL **head, int data)
{
    DBL *temp = newnode(data);
    if(*head == NULL)
    {
        *head = temp;
        return;
    }

    temp->next = *head;
    (*head)->prev = temp;
    *head = temp;
}

void insertatENd(DBL *head, int data)
{
    DBL *temp = newnode(data);
    while(head->next != NULL)
    {
        head = head->next;
    }

    head->next = temp;
    temp->prev =head;
}


void print(DBL *head)
{
    printf("Forward\n");

    while(head->next!= NULL)
    {
        printf("%d->",head->data);
        head = head->next;
    }

    printf("%d->",head->data);

    printf("Backward\n");

    printf("%d->",head->data);
    head = head->prev;
    while(head != NULL)
    {
        printf("%d->",head->data);
        head = head->prev;
    }
}


int main()
{

    DBL *head = NULL;
    insertInfront(&head,10);
    insertInfront(&head,20);
    insertInfront(&head,30);
    insertatENd(head,40);

    print(head);
    return 0;
}
