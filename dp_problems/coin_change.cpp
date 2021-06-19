#include <bits/stdc++.h>
using namespace std;      
/*
*using rec, this calc the no of ways*
*/
int coinChange_rec(int arr[], int n, int m){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(m==0){
        return 0;
    }
    return coinChange_rec(arr,n-arr[m-1],m) + coinChange_rec(arr,n,m-1);
}
/*
*using dp and this calc the no of ways*
*/
int coinChange_dp(int arr[], int n, int m){
    int dp[n+1][m];
    int i,j;
    for(j=0;j<m;j++){
        dp[0][j] = 1;
    }
    for(i=1; i<=n; i++){
        for(j=0; j<m; j++){
            int x = (i >= arr[j]) ? dp[i- arr[j]][j]: 0;
            int y = (j>=1) ? dp[i][j-1]:0;
            dp[i][j] = x+y;       
        }
    }
    return dp[n][m-1];
}


/*
*similar ques but asking the minimum number of coins to obtain the value n*
*/
int minimum_no_of_coins(int arr[], int n, int m){
    int i,j;
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if( arr[j] <= i ){
                int res = dp[i-arr[j]];
                if(res!=INT_MAX){
                    dp[i] = min(dp[i], res+1);
                }
            }
        }
    }
    if(dp[n]==INT_MAX){
        return -1;
    }
    return dp[n];
}

int main(){
    int arr[] = {1,2,3};
    int n = 4;
    int m = 3;

    cout << coinChange_rec(arr,n,m) << endl;
    cout << coinChange_dp(arr,n,m) << endl;
    cout << minimum_no_of_coins(arr,n,m) << endl;

    return 0;
}
