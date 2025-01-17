#include<stdio.h>

typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};

Node *first=NULL;

void insert_at_end(Node *head,int x)
{
    if(head==NULL)
    {
        Node *temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=NULL;
        first=temp;
        head=temp;
    }
    Node *p,*temp;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=NULL;
    p->next=temp;
}

void insert_at_beginning(Node *head,int x)
{
    Node *temp;
    temp=(Node*)malloc(sizeof(Node));
    temp->data=x;
    temp->next=first;
    first=temp;
}

void insert_at_position(Node *head,int pos,int x)
{
    if(pos==1)
    {
        Node *temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=first;
        first=temp;
    }
    else
    {
        Node *p;
        p=head;
        for(int i=0;i<pos-2 && p;i++)
        {
            p=p->next;
        }
        Node *temp;
        temp=(Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=p->next;
        p->next=temp;
    }
}

void display(Node *head)
{
    Node *p=head;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void update_at_position(Node *head,int pos,int x)
{
    Node *p;
    p=head;
    for(int i=0;i<pos-1 && p;i++)
    {
        p=p->next;
    }
    p->data=x;
}

void delete_the_first_element(Node *head)
{
    Node *temp;
    temp=first;
    first=first->next;
    free(temp);
}

void delete_the_last_element(Node *head)
{
    Node *p,*q;
    p=head;
    q=NULL;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    q->next=NULL;
    free(p);
}

void delete_the_element_at_position(Node *head,int pos)
{
    if(pos==1)
    {
        Node *temp;
        temp=first;
        first=first->next;
        free(temp);
    }
    else
    {
    Node *p,*q;
    p=head;
    q=NULL;
    for(int i=0;i<pos-1 && p;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);
    }
}

int main()
{
    int n;
    printf("Enter the number of operations to be perform:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        int operation;
        scanf("%d",&operation);

        switch(operation)
        {
        case 1:{
            int x;
            scanf("%d",&x);
            insert_at_end(first,x);
            break;
        }
        case 2:{
            int x;
            scanf("%d",&x);
            insert_at_beginning(first,x);
            break;
        }
        case 3:{
            int pos;
            int x;
            scanf("%d%d",&pos,&x);
            insert_at_position(first,pos,x);
            break;
        }
        case 4:{
            printf("\nOutput:\n");
            display(first);
            printf("\n\n");
            break;
        }
        case 5:{
            int pos;
            int x;
            scanf("%d%d",&pos,&x);
            update_at_position(first,pos,x);
            break;
        }
        case 6:{
            delete_the_first_element(first);
            break;
        }
        case 7:{
            delete_the_last_element(first);
            break;
        }
        case 8:{
            int pos;
            scanf("%d",&pos);
            delete_the_element_at_position(first,pos);
            break;
        }
        default:{
            printf("Enter the valid operation number!");
            return 0;
        }
        }
    }
    return 0;
}