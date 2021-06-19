#include <bits/stdc++.h>
using namespace std;


int knapSack(int W, int val[], int wt[], int n ){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1] > W ){
        return knapSack(W,val,wt,n-1);
    }
    return (  max(  val[n-1]+ knapSack( W-wt[n-1],val,wt,n-1 ),knapSack(W,val,wt,n-1  ) )  );
}

int knapSack_dp(int W, int val[], int wt[], int n){
    int dp[n+1][W+1];
    int i,j;
    for(i=0;i<=n;i++ ){
        dp[i][0] = 0;
    }
    for(j=0;j<=W;j++){
        dp[0][j] = 0;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=W;j++){
            if(j<wt[i-1]){
                dp[i][j] =  dp[i-1][j];
            }
            else{
                dp[i][j] = max( dp[i-1][j], val[i-1]+dp[i-1][ j-wt[i-1]]  );
            }
        }
    }
        // for(i=0;i<=n;i++){
        //     for(j=0;j<=W;j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    return dp[n][W];
}

int main(){
    int val[] = {60,100,120};
    int wt[] = {10,20,30};
    //     int val[] = {10,15,40 };
    // int wt[] = {1,2,3};
    // int W = 6;
    int W = 50;
    int n=3;
    cout << knapSack(W,val,wt,n) << endl;
    cout << knapSack_dp(W,val,wt,n) << endl;
    return 0;
}