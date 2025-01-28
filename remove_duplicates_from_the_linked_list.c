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

void merge(int arr[],int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    int temp[high+1];
    int index=0;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp[index++]=arr[left];
            left++;
        }
        else
        {
            temp[index++]=arr[right];
            right++;
        }
    }
    while(left<=mid)
    {
            temp[index++]=arr[left];
            left++;
    }
    while(right<=high)
    {
            temp[index++]=arr[right];
            right++;
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}

void merge_sort(int arr[],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
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

    merge_sort(arr,0,n-1);
    create(arr,n);
    remove_duplicates(first);
    display(first);
    return 0;
}