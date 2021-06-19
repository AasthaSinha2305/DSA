/*
*standard dp problem where we have to find possible number of ways converting a string to other*

*methods allowed are*
*1) insert*
*2) remove*
*3) replace *
*/
#include <bits/stdc++.h>
using namespace std;

/* 
*naive recursive method*
*/

int calcWays(string a,string b,int l1, int l2){
    if(l1==0){
        return l2;
    }
    if(l2==0){
        return l1;
    }
    if( a[l1-1] == b[l2-1]){
        return calcWays(a,b,l1-1,l2-1);
    }
    //if control is comming here that means that last char are not matching
    // so wo pass three rec function 1 to remove 1 to insert and one to replace
    return ( 1+
    // remove, insert, replace
    min( calcWays(a,b,l1-1,l2-1), min( calcWays( a,b,l1,l2-1)  ,calcWays( a,b,l1-1,l2-1  ) ) )  

    );
}


int calcWays_dp(string a, string b,int n,int m){
    int dp[n+1][m+1],i,j;
    for(j=0;j<=m;j++){
        dp[0][j] = j;
    }
    for(i=1;i<n;i++){
        dp[i][0] = i;     
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i][j-1], min( dp[i-1][j-1],dp[i-1][j] ) );
            }
        }
    }
    return dp[n][m];

}

int main(){
    string from = "sunday";
    string to = "saturday";
    int n = from.length();
    int m = to.length();
    cout << calcWays(from,to, n, m) << endl;

    cout << calcWays_dp(from,to,n,m) << endl;
    return 0;
}