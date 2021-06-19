/*

movement
*up right or diag*
*/


// using naive recursion

#include <bits/stdc++.h>
using namespace std;

int minPathSum_rec(vector<vector<int > > mat, int r, int c){
    if(r < 0 || c< 0){
        return INT_MAX;
    }
    else if(r==0 && c==0){
        return mat[0][0];
    }
    else{
        return mat[r][c] + min( minPathSum_rec( mat,r-1,c-1), min(minPathSum_rec(mat,r-1,c),minPathSum_rec(mat,r,c-1) )  );
    }

}

int minPathSum_dp(vector<vector<int> > mat, int r, int c ){
    int dp[r][c];
    dp[0][0] = mat[0][0];
    for(int i=1;i<=r;i++){
        dp[i][0] = dp[i-1][0] + mat[i][0];
    }
    for(int j=1; j<=c; j++){
        dp[0][j] = dp[0][j-1] + mat[0][j];
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            dp[i][j] = mat[i][j] + min(dp[i-1][j],min( dp[i][j-1],dp[i-1][j-1] ) );
        }
    }
    return dp[r][c];
}

int main(){
    int n = 3;
    vector<vector<int> > mat(n, vector<int>(n,0) );
    for(int i=0;i<n*n;i++){
        cin >> mat[i/n][i%n];
    }
    int r = 2,c =2;
    cout << minPathSum_rec(mat,r,c) << endl;
    cout << minPathSum_dp(mat,r,c) << endl; 
    return 0;
}