#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*

*using dp method finding the longest substring thst is common in both the strings*

*/
ll int commonLongestString(string s1, string s2){
    ll int len1 = s1.length();
    ll int len2 = s2.length();

    ll int i, j;

    ll int result = 0;

    ll int lSub[len1+1][len2+1];
    memset(lSub, 0 ,sizeof(lSub));

    for(i=0;i<=len1;i++){
        for(j=0; j<=len2; j++){
            if(i == 0 || j == 0){
                lSub[i][j]=0;
            }
            else if(s1[i-1] == s2[j-1]){
                lSub[i][j] = lSub[i-1][j-1] + 1;
                result = max(result,lSub[i][j]);
            }
            else{
                lSub[i][j]=0;
            }
        }
    }
    // for(i=0;i<=len1;i++){
    //     for(j=0;j<=len2;j++){
    //         cout << lSub[i][j];
    //     }
    //     cout << endl;
    // }
    return result;
}