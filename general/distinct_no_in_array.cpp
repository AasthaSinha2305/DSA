//finding number of distinct element in an array
#include <bits/stdc++.h>
using namespace std;
int distinct_element(int arr[], int n){
    int i;
    //sorting the element
    sort(arr, arr+n);
    //transverse the sorted array
    int count = 0;
    for(i=0;i<n;i++){
        while(i < n-1, arr[i] == arr[i+1]){
            i++;
        }
        count++;
    }
    return count;
}
int main(){
    int a[] = {1,2,3,4,5,5,6,7,8,9,0};
    int n = sizeof(a)/sizeof(a[0]);
    cout << "NO. OF DISTINCT ELEMNENTS IS " << distinct_element(a, n) << endl;
    return 0;
}