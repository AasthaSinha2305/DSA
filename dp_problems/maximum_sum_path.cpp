/*    movement allowed 
       * 0 *
      * /|\ *
     * / | \ *
   *  /  |  \  *
*/ 


#include <bits/stdc++.h>
using namespace std;


int maxSumPath(int n, vector<vector<int> > Mat){
    int dp[n+1][n+1];
    for(int j=0;j<n;j++){
        dp[0][j] = Mat[0][j];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==0 && j+1 <n){
                dp[i][j] = Mat[i][j] + max( dp[i-1][j+1],dp[i-1][j]);
            }
            else if(j==n-1 && j-1>=0){
                dp[i][j] = Mat[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
            else if(j>0 && j<n-1){
                dp[i][j] = Mat[i][j] + max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1] )  );
            }
            else{
                dp[i][j] = Mat[i][j] + dp[i-1][j];
            }
        }
    }
    int MaxValue = -1;
    for(int j = 0; j< n; j++){
        MaxValue = max(MaxValue, dp[n-1][j]);
    }
    return MaxValue;

}

int main(){
    int n;
    n =  3;
    vector<vector<int> > Mat(n, vector<int>(n,0));
    for(int i=0;i<n*n;i++){
        cin >> Mat[i%n][i/n];
    }
    cout << maxSumPath(n,Mat);

}