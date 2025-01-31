#include<stdio.h>

typedef struct queue queue;

struct queue
{
    int size;
    int front;
    int rear;
    int *q;
};

int isfull(queue *Q)
{
    if(Q->rear==Q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(queue *Q)
{
    if(Q->front==Q->rear)
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
    if(isfull(Q))
    {
        printf("Queue is Full.");
        return;
    }
    else
    {
        Q->q[++Q->rear]=x;
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
       x=Q->q[++Q->front];
    }
}

int peek(queue *Q)
{
    int x=-1;
    if(isEmpty(Q))
    {
        printf("Queue is empty.");
        return 0;
    }
    else
    {
        if(Q->front==-1)
        {
            printf("\n front at -1 index.");
            return 0;
        }
        else
        {
            x=Q->q[Q->front+1];
            return x;
        }
    }
}

int size(queue *Q)
{
    int count=0;
    for(int i=Q->front+1;i<=Q->rear;i++)
    {
        count++;
    }
    return count;
}

void display(queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue is empty");
        return;
    }
    else
    {
        for(int i=Q->front+1;i<=Q->rear;i++)
        {
            printf("%d ",Q->q[i]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    queue *Q=(queue*)malloc(sizeof(queue));
    Q->size=n;
    Q->front=-1;
    Q->rear=-1;
    Q->q=(int*)malloc(Q->size*sizeof(int));
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        int element;
        scanf("%d",&element);
        enqueue(Q,element);
    }
    display(Q);
    dequeue(Q);
    display(Q);
    printf("\nRetrieve the front element without removing it:%d",peek(Q));
    printf("\nSize of Queue:%d",size(Q));
    return 0;
}