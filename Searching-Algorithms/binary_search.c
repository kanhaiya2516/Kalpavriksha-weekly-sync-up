#include<stdio.h>

int cmp(const void *a,const void *b)
{
    return (*(int*)a - *(int*)b);
}

int binary_search(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
        int mid=low+(high-low)/2;

        if(arr[mid]==key)
        {
            return mid;
        }

        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else if(arr[mid]>key)
        {
            high=mid-1;
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

    qsort(arr,n,sizeof(int),cmp);
    int key;
    printf("Enter element you want to search in array:");
    scanf("%d",&key);

    int index=binary_search(arr,0,n-1,key);
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