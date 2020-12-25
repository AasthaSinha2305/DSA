#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l, int h){
    int i, j;
    i = l - 1;
    int pivot = arr[h];
    for(j=l; j<=h-1; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return (i+1);

}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high );
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }

}
void printArray(int arr[], int n){
    int i;
    cout << "The array: ";
    for(i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    int n,i,j;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];
    for(i=0; i<n; i++){
        cout << "Enter the element: ";
        cin >> a[i];
    }
    printArray(a, n);
    quickSort(a, 0, n-1);
    printArray(a, n);
}