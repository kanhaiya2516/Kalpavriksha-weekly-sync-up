#include<stdio.h>
#include<math.h>

typedef struct Node Node;

struct Node
{
    Node *prev;
    int data;
    Node *next;
};

Node *first1=NULL;
Node *first2=NULL;
Node *dummyNode=NULL;


void create_list1(int arr[],int n)
{
    first1=(Node*)malloc(sizeof(Node));
    first1->prev=NULL;
    first1->data=arr[0];
    first1->next=NULL;
    Node *last;
    last=first1;
    for(int i=1;i<n;i++)
    {
        Node *t=(Node*)malloc(sizeof(Node));
        t->data=arr[i];
        t->next=last->next;
        last->next=t;
        t->prev=last;
        last=t;
    }
}

void create_list2(int arr[],int n)
{
    first2=(Node*)malloc(sizeof(Node));
    first2->prev=NULL;
    first2->data=arr[0];
    first2->next=NULL;
    Node *last;
    last=first2;
    for(int i=1;i<n;i++)
    {
        Node *t=(Node*)malloc(sizeof(Node));
        t->data=arr[i];
        t->next=last->next;
        last->next=t;
        t->prev=last;
        last=t;
    }
}

void merge(Node *list1,Node *list2)
{
    dummyNode=(Node*)malloc(sizeof(Node));
    dummyNode->prev=NULL;
    dummyNode->data=-1;
    dummyNode->next=NULL;
    Node *temp;
    temp=dummyNode;

    while(list1!=NULL && list2!=NULL)
    {
        if(list1->data < list2->data)
        {
            temp->next=list1;
            list1->prev=temp;
            temp=list1;
            list1=list1->next;
        }
        else
        {
            temp->next=list2;
            list2->prev=temp;
            temp=list2;
            list2=list2->next;
        }
    }
    if(list2)
    {
        temp->next=list2;
        list2->prev=temp;
    }
    else if(list1)
    {
        temp->next=list1;
        list1->prev=temp;
    }
    dummyNode=dummyNode->next;
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
    int n1;
    printf("Enter the number of First list1:");
    scanf("%d",&n1);
    int a1[n1];
    printf("Enter the elements of first list1:\n");
    for(int i=0;i<n1;i++)
    {
        scanf("%d",&a1[i]);
    }

     int n2;
    printf("Enter the number of Second list2:");
    scanf("%d",&n2);
    int a2[n2];
    printf("Enter the elements of Second list2:\n");
    for(int i=0;i<n2;i++)
    {
        scanf("%d",&a2[i]);
    }

    create_list1(a1,n1);
    create_list2(a2,n2);
    if(first1==NULL || first2==NULL)
    {
        printf(" ");
        return 0;
    }
    merge(first1,first2);
    printf("Resulted List:");
    display(dummyNode);
    return 0;
}