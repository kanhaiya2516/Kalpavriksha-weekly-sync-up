#include<stdio.h>

typedef struct queue queue;
typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};

struct queue
{
    int size;
    Node *front;
    Node *rear;
};

int isEmpty(queue *Q)
{
    if(Q->rear==Q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(queue *Q,int x)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("Queue is full.");
        return;
    }
    temp->data=x;
    temp->next=NULL;
    if(Q->front==NULL && Q->rear==NULL)
    {
        Q->front=Q->rear=temp;
    }
    else
    {
        Q->rear->next=temp;
        Q->rear=temp;
    }
}

void dequeue(queue *Q)
{
    int x=-1;
    if(isEmpty(Q))
    {
        printf("Queue is empty.");
        return;
    }
    else
    {
        Node *temp=Q->front;
        Q->front=Q->front->next;
        x=temp->data;
        free(temp);
    }
}

int peek(queue *Q)
{
    int x=-1;
    if(Q->front==NULL)
    {
        return -1;
    }
    else
    {
        x=Q->front->data;
        return x;
    }
}

int size(queue *Q)
{
    int count=0;
    Node *p=Q->front;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count++;
}

void display(queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty.");
        return;
    }
    else
    {
        Node *p=Q->front;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    queue *Q=(queue*)malloc(sizeof(queue));
    Q->size=n;
    Q->front=NULL;
    Q->rear=NULL;
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        int element;
        scanf("%d",&element);
        enqueue(Q,element);
    }
    display(Q);
    printf("\nRetrieve the front element without removing it:%d",peek(Q));
    printf("\nThe number of elements in the queue:%d",size(Q));
    if(isEmpty(Q))
    {
        printf("\nQueue is empty.");
    }
    else
    {
        printf("\nQueue is not empty.");
    }
    return 0;
}