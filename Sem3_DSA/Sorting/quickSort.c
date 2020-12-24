#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[],int, int);
int partition(int arr[],int, int);
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
    quickSort(a,0,n-1);
    printArray(a,n);
    return 0;
}
void quickSort(int arr[],int low, int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    for(int j = low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}

void printArray(int arr[], int l){
    int i;
    printf("The array after quick sort: ");
    for(i=0; i<l; i++){
        printf("%d ",arr[i]);
    }
}
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}