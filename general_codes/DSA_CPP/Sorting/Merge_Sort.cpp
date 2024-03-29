#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int l, int m ,int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++){
        R[j] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    int i, j, m;
    m = (l + r-1)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l , m ,r);
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
    mergeSort(a, 0, n-1);
    printArray(a, n);
}