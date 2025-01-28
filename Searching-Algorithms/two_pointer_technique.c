#include<stdio.h>

int two_pointer_technique(int arr[],int left,int right,int target,int *left_index,int *right_index)
{
    while(left<right)
    {
        int sum=arr[left]+arr[right];
        if(sum==target)
        {
            *left_index=left;
            *right_index=right;
            return 1;
        }
        else if(sum<target)
        {
            left++;
        }
        else
        {
            right--;
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

    int target;
    printf("Enter the target value:");
    scanf("%d",&target);
    int left_index=0,right_index=0;

    int result=two_pointer_technique(arr,0,n-1,target,&left_index,&right_index);
    if(result==-1)
    {
        printf("Target is not found.");
    }
    else
    {
        printf("Target is found at index:[%d,%d]",left_index,right_index);
    }
    return 0;
}