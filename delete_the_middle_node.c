#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node
{
    char data;
    Node *next;
};

Node *first=NULL;

void create(char a[],int n)
{
    first=(Node*)malloc(sizeof(Node));
    first->data=a[0];
    first->next=NULL;
    Node *last;
    last=first;
    for(int i=1;i<n;i++)
    {
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->data=a[i];
        temp->next=NULL;
        last->next=temp;
        last=last->next;
    }
}

void display(Node *head)
{
    head=first;
    while(head!=NULL)
    {
        printf("%c ",head->data);
        head=head->next;
    }
}

void middle(Node *head)
{
    Node *p,*slow,*fast;
    slow=head;
    fast=head;
    p=NULL;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        p=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    p->next=slow->next;
    free(slow);
}

int main()
{
    int n;
    printf("Enter the number of character:");
    scanf("%d",&n);
    if(n==0 || n==1)
    {
        printf(" ");
        return 0;
    }
    char a[n];
    char ch;
    scanf("%c",&ch);
    printf("Enter the character elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%c",&a[i]);
    }
    create(a,n);
    printf("Original Linked List:");
    display(first);
    middle(first);
    printf("\nAfter the deletion of middle node:");
    display(first);
    return 0;
}