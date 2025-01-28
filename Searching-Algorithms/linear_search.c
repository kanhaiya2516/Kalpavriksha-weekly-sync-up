#include<stdio.h>

int search(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
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

    int key;
    printf("Enter element you want to search in array:");
    scanf("%d",&key);

    int index=search(arr,n,key);
    if(index==-1)
    {
        printf("Element is not found.");
    }
    else
    {
        printf("Element is found at index:%d",index);
    }
    return 0;
}