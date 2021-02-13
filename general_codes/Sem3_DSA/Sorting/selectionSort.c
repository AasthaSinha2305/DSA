#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[],int);
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
    selectionSort(a,n);
    printArray(a,n);
    return 0;
}
void selectionSort(int arr[],int l){
    int i,j,minIndex;
    printf("The array after selection sort: ");
    for(i=0; i<l; i++){
        minIndex = i;
        for(j= i+1; j<l; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(&arr[i],&arr[minIndex]);
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