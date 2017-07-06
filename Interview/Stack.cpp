#include <iostream>

using namespace std;

typedef struct node{
    int data;
    struct node *next;
}Snode;

struct node * newnode(int data)
{
    struct node *temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
};

void push(struct node **head, int data)
{
    struct node *temp = newnode(data);
    temp->next = *head;
    *head = temp;
}

int pop(struct node **head)
{
    int data = 0;
    if(*head == NULL)
    {
        cout << "Stack is empty\n";
        return 0;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    data = temp->data;
    delete temp;
    cout << "\n" << data;
    return data;
}

void printStack(Snode *temp)
{
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Snode *pStack = NULL;
    push(&pStack,10);
    push(&pStack,20);
    push(&pStack,30);
    push(&pStack,40);

    printStack(pStack);

    pop(&pStack);
    pop(&pStack);
    pop(&pStack);
    pop(&pStack);
    pop(&pStack);

    return 0;
}
