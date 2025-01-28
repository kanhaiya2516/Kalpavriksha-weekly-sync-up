#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int a[],int start,int end)
{
    int pivot=a[start];
    int i=start+1;
    int j=end;
    while(i<=j)
    {
        while(a[i]<=pivot && i<=j)
        {
          i++;
        }

       while(a[j]>pivot)
       {
          j--;
       }

       if(i<j)
       {
        swap(&a[i],&a[j]);
       }
    }
    swap(&a[start],&a[j]);
    return j;
}

void quick_sort(int a[],int l,int h)
{
    if(l<h)
    {

        int k=partition(a,l,h);
        quick_sort(a,l,k-1);
        quick_sort(a,k+1,h);
    }
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
    int l=0;
    int h=n-1;
    quick_sort(a,l,h);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}