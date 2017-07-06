#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Qnode;


typedef struct Queue{
    Qnode *front,*rear;
}Q;


Qnode *front =NULL;
Qnode *rear =NULL;

Qnode * Qnewnode(int data)
{
    Qnode *node  = (Qnode*)malloc(sizeof(Qnode));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Queue * CreateQueue()
{
    struct Queue *q = (Q *)malloc(sizeof(Q));
    q->front = q->rear = NULL;
    return q;
}

void Enqueue(Q *queue, int data)
{
    Qnode * node = Qnewnode(data);
    if(queue->rear == NULL){
        queue->front = queue->rear = node;
        return;
    }
    queue->rear->next =node;
    queue->rear = node;
}

void Dequeue(Q *queue)
{
    Qnode * temp = queue->front;
    if(queue->front == NULL){
        return;
    }
    if(queue->front == queue->rear)
    {
        queue->front = queue->rear = NULL;
        free(temp);
        return;
    }
    queue->front = queue->front->next;
    free(temp);
}

void Enq(int data)
{
    Qnode *temp = Qnewnode(data);
    if(front == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
void Deq()
{
    Qnode *temp = front;
    if(front == NULL)
        return;
    if(front == rear)
    {
        front = rear = NULL;
        return;
    }
    front = front->next;
    free(temp);
}

void print(Qnode *front)
{
    while(front != NULL)
    {
        printf("%d--",front->data);
        front = front->next;
    }
}

#define MAX 20
class CQueue
{
    int A[MAX];
    int front,rear;

public:
    CQueue(): front(-1),rear(-1){};
    void enque(int data);
    void deque();
};


void CQueue ::enque(int data)
{
    if(front == rear)
        front = rear = 0;
    rear = (rear + 1)% MAX;
    A[rear] = data;
}
int main()
{

    Enq(10);
    Enq(20);
    Enq(30);
    Enq(40);

    Enq(10);
    Enq(20);
    Enq(30);
    Enq(40);

    Deq();
    Deq();

  //  print(front);


    Q  *queue = CreateQueue();

    Enqueue(queue,10);
    Enqueue(queue,20);
    Enqueue(queue,30);
    Enqueue(queue,40);

    Dequeue(queue);
    Dequeue(queue);

    print(queue->front);

    return 0;
}

