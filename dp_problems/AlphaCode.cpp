// #include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define fo(i, n) for (i = 0; i < n; i++)
#define ll long long
 


ll int solve(string s){
    // for(int i=0;i<s.length();i++){
    //     cout << abs((int)s[i] - 48) << " ";
    // }
    // cout << endl;
    ll int dp[5005];
    // memset(dp,0,sizeof(dp));
    dp[0]=1;
    dp[1] =1;
    // dp[1] = 1;
    // cout << dp[0] << " " << dp[1] << " ";
    for(ll int i=2;i<=s.length();i++){
        if(s[i-1] != '0'  ){
            dp[i] = dp[i-1];
        }
        
        ll int d = abs( 48 - (ll int)(s[i-2]) )*10 + abs( 48 - (ll int)(s[i-1]) );
        if( d <=26 && d>=10 ){
            
            // cout << " d " << d << " ";
            // cout << d << endl;
            // cout << dp[i] << endl;
            dp[i]+=dp[i-2];
            // cout << dp[i] << endl;
        }
        // cout << dp[i] <<  " ";
    }
    // cout << endl;
    return dp[s.length()];

} 
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll int t, n, i, j, k;
    string s;
    while( (cin >> s)){
        
        if(s == "0"){
            break;
        }
        cout << solve(s) << endl;

    }
    return 0;
}