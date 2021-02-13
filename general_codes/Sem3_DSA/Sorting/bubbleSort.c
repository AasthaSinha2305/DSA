#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[],int);
void printArray(int arr[], int);
void swap(int *,int *);

int main()
{
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubbleSort(a,n);
    printArray(a,n);
    return 0;
}
void bubbleSort(int arr[],int l){
    int i,j;
    printf("Array after bubble sort is: ");
    for(i=0; i<l-1; i++){
        int flag = 0;
        for(j=0; j<l-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}
void printArray(int arr[], int l){
    int i;
    for(i=0; i<l; i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}