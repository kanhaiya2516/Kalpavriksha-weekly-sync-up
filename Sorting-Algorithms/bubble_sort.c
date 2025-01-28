#include<stdio.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
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

    bubble_sort(a,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}