#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[],int);
void printArray(int arr[], int);
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
    insertionSort(a,n);
    printArray(a,n);
    return 0;
}
void insertionSort(int arr[],int l){
    int i,j,key;
    printf("The array after insertion sort: ");
    for(i=1;i<l;i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void printArray(int arr[], int l){
    int i;
    for(i=0; i<l; i++){
        printf("%d ",arr[i]);
    }
}