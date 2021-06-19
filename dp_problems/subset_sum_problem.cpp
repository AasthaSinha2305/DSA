#include <bits/stdc++.h>
using namespace std;

// naive recursive solution

bool isSubsetSum_rec( int arr[], int n, int sum ){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(arr[n-1]>sum){
        return isSubsetSum_rec(arr, n-1, sum);
    }

    return (

        isSubsetSum_rec(arr,n-1,sum) || isSubsetSum_rec(arr,n-1, sum-arr[n-1] )
    );
}

// dp approach
bool isSubsetSum_dp(int arr[], int n, int sum){
    bool dp[n+1][sum+1];     
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;        
    }
    for(int j = 1; j<=sum; j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1; j<=sum; j++){
            if(j<arr[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int n = 6;
    int sum = 1;
    if(isSubsetSum_dp(arr, n, sum) ){
        cout <<  ("Found")  << endl;
    }
    else{
        cout << ("Not Found") << endl;
    }

    return 0;
}