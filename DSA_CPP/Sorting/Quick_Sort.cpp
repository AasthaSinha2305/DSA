#include <bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int l, int r){

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