#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int left=low;
    int right=mid+1;
    int temp[high+1];
    int index=0;
    while(left<=mid && right<=high)
    {
        if(a[left]<=a[right])
        {
            temp[index++]=a[left];
            left++;
        }
        else
        {
            temp[index++]=a[right];
            right++;
        }
    }
    while(left<=mid)
    {
            temp[index++]=a[left];
            left++;
    }
    while(right<=high)
    {
            temp[index++]=a[right];
            right++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=temp[i-low];
    }
}

void merge_sort(int a[],int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int mid=(low+high)/2;
    merge_sort(a,low,mid);
    merge_sort(a,mid+1,high);
    merge(a,low,mid,high);
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enetr the elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    merge_sort(a,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}