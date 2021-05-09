#include <bits/stdc++.h>
using namespace std;
#define ll long long 
/*
*naive way for searching a pattern in a particular string*
*return the number of occurence of that particular pattern (brute force)*
*/
ll int countFreq(string source, string tomatch){
    ll int n = source.length();
    ll int m = tomatch.length();
    ll int j,i, ans=0;
    for(ll int i = 0; i<= n-m; i++){
        for(j=0;j<m;j++){
            if(source[i+j] != tomatch[j] ){
                break;
            }
        }
        if(j==m){
            ans++;
        }
    
    }
    return ans;

}

/*
*KMP for pattern searching oin O(n) time*
*/

