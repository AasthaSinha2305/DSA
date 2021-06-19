#include <bits/stdc++.h>
using namespace std;


int maximumSubArray(int arr[], int n){
    int sum = arr[0];
    int best = arr[0];
    for(int i=1;i<n;i++){
        sum = max(arr[i],sum+arr[i]);
        best = max(best,sum);
    }
    return best;
}

int main(){
    int arr[] = {-1,-2,-39,-3};
    int n = 4;
    int ans = maximumSubArray(arr,n);
    cout << ans << endl;
}