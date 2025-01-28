#include <stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b)
 {
    return (*(int *)a - *(int*)b);
 }

int equal_to_sum(int sub[], int len, int target)
{
  int sum = 0;
  for (int i = 0; i < len; i++)
  {
    sum += sub[i];
  }
  if (sum == target)
  {
    return 1;
  }
  return 0;
}
void findsubset(int arr[], int index, int target, int subset[], int subsetlen, int n)
 {
  if (equal_to_sum(subset, subsetlen, target))
  {
    for (int i = 0; i < subsetlen; i++)
    {
      printf("%d ", subset[i]);
    }
    printf("\n");
  }

  for (int i = index; i < n; i++)
  {
    if (i > index && arr[i - 1] == arr[i])
    {
      continue;
    }
    subset[subsetlen] = arr[i];
    findsubset(arr, i + 1, target, subset, subsetlen + 1, n);
  }
}

int main()
 {
  int n;
  printf("Enter number of elements:");
  scanf("%d",&n);

  int arr[n], sub[n];
  printf("Enter the elements:");
  for (int i=0; i<n; i++)
  {
    scanf("%d",&arr[i]);
  }

  printf("Enter the target want to search:");
  int target;
  scanf("%d",&target);

  qsort(arr, n, sizeof(int), compare);

  printf("Subsets having target: %d\n", target);
  findsubset(arr, 0, target, sub, 0, n);

  return 0;
}