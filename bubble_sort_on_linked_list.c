#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};
Node *first=NULL;

void create(int arr[],int n)
{
    Node *last,*t;
    first=(Node*)malloc(sizeof(Node));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(Node*)malloc(sizeof(Node));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void bubble_sort(Node *head)
{
    Node *p=head;
    Node *q=head;
    Node *len=head;
    int n=0;
    while(len!=NULL)
    {
        n++;
        len=len->next;
    }

    for(int i=0;i<n-1;i++)
    {
        q=head;
        for(int j=0;j<n-1-i;j++)
        {
            if(q->data > q->next->data)
            {
                int temp;
                temp=q->data;
                q->data=q->next->data;
                q->next->data=temp;
            }
            q=q->next;
        }
        p=p->next;
    }
}

void display(Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

int main()
{
    int n;
    printf("Number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create(arr,n);
    bubble_sort(first);
    display(first);
    return 0;
}