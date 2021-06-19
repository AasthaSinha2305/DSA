#include <bits/stdc++.h>
using namespace std;


int minSumSubarray1(int arr[], int n){
    int sum = arr[0];
    int best = arr[0];
    for(int i=0;i<n;i++){
        sum = min(sum+arr[i],arr[i]);
        best = min(best,sum);
    }
    return best;
    

}


int minSumSubarray(int arr[], int n){
    int minsofar =  INT_MAX;
    int mintillnow = INT_MAX;
    for(int i=0;i<n;i++){
        if(mintillnow>0){
            mintillnow = arr[i];
        }
        else{
            mintillnow+=arr[i];
        }
        minsofar = min(minsofar,mintillnow);
    }
    return minsofar;
}

int main(){
    int arr[] = {3, -4, 2, -3, -1, 7, -5};
    // int arr[] = {5,2,3,4,5};
    int n =  sizeof(arr)/sizeof(arr[0]);
    cout << minSumSubarray1(arr,n) << endl;
    cout << minSumSubarray(arr,n) << endl;
    return 0;
}