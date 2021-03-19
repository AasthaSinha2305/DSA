/*

*Length of the longest substring without repeating characters*

*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define NO_OF_CHAR 500

ll int longestString(string s){
    ll int n = s.size();

    ll int ans =0;
    vector <ll int> lastIndex (NO_OF_CHAR, -1);
    ll int i=0;
    for(ll int j=0; j < n; j++){
        i = max(i,lastIndex[s[j]]+1);
        ans = max(ans, j-i+1);
        lastIndex[s[j]] = j;
    }
    return ans;
}