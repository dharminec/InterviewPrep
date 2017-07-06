#include <stdio.h>
#include <stdlib.h>


struct Qnode
{
  struct BSTNode *bstnode;
  struct Qnode *next;
};

struct Qnode * QNewnode(struct BSTNode * head)
{
    struct Qnode *temp = new Qnode();
    temp->next = NULL;
    temp->bstnode = head;
    return temp;
}
struct BSTNode
{
    int data;
    struct BSTNode *right;
    struct BSTNode *left;
};

struct Queue
{
    struct Qnode *front, *rear;
};

struct Queue * CreateQueue()
{
    struct Queue * temp = (struct Queue *)malloc(sizeof(struct Queue));
    temp->front = temp->rear = NULL;
    return temp;
};

struct Queue *LeefQue = CreateQueue();

void Enqueue(struct Queue *q ,struct BSTNode *head)
{
    struct Qnode *temp = QNewnode(head);
    if(q->front == NULL)
    {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

struct BSTNode *Deque(struct Queue *q)
{
    struct Qnode *temp = q->front;
    if(q->front == NULL){
        q->rear = NULL;
        return NULL;
    }

    q->front = q->front->next;
    return temp->bstnode;
};

bool isQueEmpty(struct Queue *q)
{
    return q->front== NULL;
}

 struct BSTNode *peekQueue(struct Queue *q)
{
    return q->front->bstnode;
}
struct BSTNode * newnode(int data)
{
    struct BSTNode *temp = (struct BSTNode *)malloc(sizeof(struct BSTNode));
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
};

struct BSTNode *insertBSTNode(struct BSTNode *head,int data)
{
    if(head == NULL)
    {
        struct BSTNode *temp = newnode(data);
        head = temp;
    }
    else
    {
        if(data <= head->data)
            head->left  = insertBSTNode(head->left,data);
        else
            head->right  = insertBSTNode(head->right,data);
    }
    return head;
};

void print(struct BSTNode *head)
{
    if(head == NULL)
        return;
    print(head->left);
    printf("%d ", head->data);
    print(head->right);
}

void printQue(struct Queue *q)
{
    while(q->front != NULL){
        printf("%d ",q->front->bstnode->data);
        q->front = q->front->next;
    }

    printf("\n");
}
void LevelOrderTravelPrint(BSTNode *head)
{
    struct Queue *BSTQue = CreateQueue();
  //  Enqueue(BSTQue,head);
    struct BSTNode *temp = head;
    while(temp)
    {
        printf("%d ",temp->data);
        if(temp->left !=NULL)
            Enqueue(BSTQue,temp->left);
        if(temp->right !=NULL)
            Enqueue(BSTQue,temp->right);
        temp = Deque(BSTQue);
    }
    return;
}

int HightofTree(BSTNode *head)
{
    if(head==NULL){
        printQue(LeefQue);
        return -1;
    }

    Enqueue(LeefQue,head);
    int lhight = HightofTree(head->left);
    Deque(LeefQue);
    int lright = HightofTree(head->right);

    if(lhight >lright)
        return lhight+1;
    return lright+1;

}


int main()
{

    struct BSTNode *head = NULL;

    head = insertBSTNode(head,10);
    head = insertBSTNode(head,20);
    head = insertBSTNode(head,30);
    head = insertBSTNode(head,5);
    head = insertBSTNode(head,4);
    head = insertBSTNode(head,1);
    head = insertBSTNode(head,6);
    head = insertBSTNode(head,7);
    head = insertBSTNode(head,8);
    head = insertBSTNode(head,15);


    print(head);
    printf("\n\n");
    LevelOrderTravelPrint(head);

    printf("\n\n");
    printf("Hight of Tree = %d",HightofTree(head));

    return 0;
}
