#include <bits/stdc++.h>
using namespace std;
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n){
    int i;
    cout << "The array: ";
    for(i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void selectionSort(int arr[], int n){
    int i, j, min;
    for(i=0; i<n; i++){
        min = i;
        for(j= i+1; j<n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
    cout << "Selection Sort Implemented" << endl;
}
int main(){
    int n,i,j;
    cout << "Enter the number of element: ";
    cin >> n;
    int a[n];
    for(i=0; i<n; i++){
        cout << "Enter the elemnt: ";
        cin >> a[i];
    }
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
}