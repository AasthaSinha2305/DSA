
#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<ll int, ll int> mp;

ll int solve(ll int n){
    if(n<=1){
        return n;
    }
    if(mp[n]){
        return mp[n];
    }
    ll int val2 = max(n/2 , solve(n/2) );
    ll int val3 = max(n/3 , solve(n/3) );
    ll int val4 = max(n/4 , solve(n/4) );
    mp[n]  = max(n,  val2+val3+val4 );
    return mp[n];
}



int main(){
    ll int n;
    while(cin >> n){
        cout << solve(n) << endl;
    }
    return 0;
}
