/*  

* finding a longest continuous elements subsets with most distinct number *     

 */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll int largestSubset(ll int a[], ll int n){
    unordered_map <ll int , ll int> m;
    ll int ans =0, i , j =0;
    for(i=0; i<n; i++){
        j = max(m[a[i]],j);
        ans = max(ans, i - j + 1);
        m[a[i]] = i+1;
    }
    return ans;

}

/*
*Cautious note: elements index should start from 1*
*/
ll int uniqueElementsSet(ll int a[],ll int n )
{
    ll int ans =0,i,j;
    map <ll int, ll int> lastIndex;
    i=1;
    for(j=1;j<=n;j++){
        i= max(i,lastIndex[a[j]]+1);
        ans = max(ans, j-i+1);
        lastIndex[a[j]] = j;
    }
    return ans;

}