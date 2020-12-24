#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr1[], int key1, int low, int high){
    if(high <= low){
        return ((key1 > arr1[low] )? (low+1) : low);
    }
    int mid = (low + high) / 2;
    if(key1 == arr1[mid]){
        return mid+1;
    }
    if(key1 > arr1[mid]){
        return binarySearch(arr1, key1, mid+1, high);
    }
    return binarySearch(arr1, key1, low, mid-1);
}

void insertionSort(int arr[], int num){
    int i, j, key, loc;
    for(i=1 ;i< num; i++){
        key = arr[i];
        j = i-1;
        loc = binarySearch(arr, key, 0, j);
        while(j >= loc){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << "insertion Sort implemented" << endl;
}

void printArray(int arr[], int num){
    int i;
    cout << "The array is: ";
    for(i=0; i<num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int n, i;
    cout << "Enter the number of Elements: ";
    cin >> n;
    int a[n];
    for(i=0;i<n;i++){
        cout << "Enter the element: ";
        cin >> a[i];
    }
    printArray(a, n);
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}