#include<stdio.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selection_sort(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=i,k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
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
    selection_sort(a,n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}