#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int num){
    int i, j, key;
    for(i=1 ;i< num; i++){
        key = arr[i];
        j = i-1;
        while(j >=0 && arr[j] > key){
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