#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int N) {
    for (int i = 1; i < N; i++) {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}
int main() {
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enetr the elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    insertionSort(a,n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}