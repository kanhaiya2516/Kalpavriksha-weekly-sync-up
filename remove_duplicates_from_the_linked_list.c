#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;

struct Node
{
    int data;
    Node *next;
};

Node *first=NULL;

void create(int arr[],int n)
{
    first=(Node*)malloc(sizeof(Node));
    first->data=arr[0];
    first->next=NULL;
    Node *last;
    last=first;
    for(int i=1;i<n;i++)
    {
        Node *temp=(Node*)malloc(sizeof(Node));
        temp->data=arr[i];
        temp->next=NULL;
        last->next=temp;
        last=last->next;
    }
}

void display(Node *head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
}

void splitList(struct Node* source, struct Node** front, struct Node** back)
 {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

struct Node* mergeLists(struct Node* a, struct Node* b)
{
    if (a == NULL) return b;
    if (b == NULL) return a;

    struct Node* result = NULL;

    if (a->data <= b->data) {
        result = a;
        result->next = mergeLists(a->next, b);
    } else {
        result = b;
        result->next = mergeLists(a, b->next);
    }
    return result;
}


void mergeSort(struct Node** headRef)
 {
    struct Node* head = *headRef;
    if (head == NULL || head->next == NULL)
    {
        return;
    }

    struct Node* a;
    struct Node* b;

    splitList(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headRef = mergeLists(a, b);
}
void remove_duplicates(Node *head)
{
    Node *p,*q;
    p=head->next;
    q=head;
    while(p!=NULL)
    {
        if(p->data==q->data)
        {
            Node *temp;
            temp=p;
            p=p->next;
            q->next=p;
            free(temp);
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    create(arr,n);
    mergeSort(&first);
    remove_duplicates(first);
    display(first);
    return 0;
}