#include<stdio.h>

void sort(int *arr,int n)
{
   int *low=arr;
   int *mid=arr;
   int *high=arr+n-1;

   while(mid<=high)
   {
     if(*mid==0)
     {
         int temp;
         temp=*mid;
         *mid=*low;
         *low=*mid;
         low++;
         mid++;
     }
     else if(*mid==1)
     {

         mid++;
     }
     else if(*mid==2)
     {
         int temp;
         temp=*mid;
         *mid=*high;
         *high=temp;
         high--;
     }
   }
}
int main()
{
    int nums[100];
    int items;
    printf("Enter the items:");
    scanf("%d",&items);
    printf("Enter the nums values:\n");
    for(int i=0;i<items;i++)
    {
        scanf("%d",&nums[i]);
    }
    sort(nums,items);
    printf("Sorted values:\n");
    for(int i=0;i<items;i++)
    {
      printf("%d\n",nums[i]);
    }
    return 0;
}