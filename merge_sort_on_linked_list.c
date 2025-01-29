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

Node *find_middle(Node *head)
 {
    if (head==NULL || head->next==NULL)
        return head;
    Node *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
 {
    if (left==NULL)
        return right;
    if (right==NULL)
        return left;

    Node *dummy = (Node *)malloc(sizeof(Node));
    Node *temp = dummy;

    while (left && right)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }

    }

    if (left)
        temp->next = left;
    if (right)
        temp->next = right;

    Node *result = dummy->next;
    free(dummy);
    return result;
}

Node *merge_sort(Node *head)
 {
    if (head==NULL || head->next==NULL)
        return head;

    Node *mid = find_middle(head);
    Node *right_half = mid->next;
    mid->next = NULL;

    Node *left = merge_sort(head);
    Node *right = merge_sort(right_half);

    return merge(left, right);
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
    Node *result1=merge_sort(first);
    first=result1;
    display(first);
    return 0;
}