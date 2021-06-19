#include <bits/stdc++.h>
using namespace std;
#define ll long long
 


/*
*using naive recursion call  ( time complexity ----->  O(2^n) ) *
*/ 

ll int lcs_r( string a, string b, ll int len1, ll int len2  ){
    if(len1 ==0 || len2 ==0   ){
        return 0;
    }
    if( a[len1 -1 ]  ==  b[len2-1 ] ){
        return 1 + lcs_r( a,b, len1-1 , len2-1  );
    }
    else{
        return max( lcs_r( a,b,len1, len2-1  ), lcs_r(a,b, len1-1, len2 )    );
    }
}


ll int lcs_dp(string a, string b, ll int len1, ll int len2  ){
    ll int dp[ len1 +1 ][ len2 + 1 ];
    ll int i,j;
    for(i=0;i<=len1;i++){
        dp[i][0] = 0;
    }
    for(j=0;j<=len2; j++){
        dp[0][j] = 0;
    }
    for(i=1;i<=len1;i++){
        for(j=1;j<=len2;j++){
            
            if(a[i-1] == b[j-1]  ){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] =  max( dp[i-1][j],dp[i][j-1]  );
            }
        }
    }
    // for(i=0;i<=len1;i++){
    //     for(j=0;j<=len2;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[len1][len2];
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll int t, n, i, j, k;
    string a,b;
    cin >> a;
    cin >> b;

    ll int len1 = a.length();
    ll int len2 = b.length();

    cout <<  ( lcs_r( a,b,len1,len2  )  )  << endl;
    // debo("________");
    cout <<  lcs_dp(a,b,len1,len2)  << endl;
    return 0;
}