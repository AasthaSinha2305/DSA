#include <bits/stdc++.h>
using namespace std;
#define ll long long






/*
*linear time method to count number of ways to divide array in three parts such that sum is equal of os three divided parts*
*/

ll int countWays(ll int a[] , ll int n){
    ll int cnt[n]={0};
    ll int i,sum=0;                                                     
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum%3!=0){
        return 0;
    }
    ll int sum3 = sum/3;
    ll int s=0;
    for(i=n-1;i>=0;i--){
        s+=a[i];
        if(s==sum3){
            cnt[i] = 1;
        }
    }
    // for(i=0;i<n;i++){
    //     cout << a[i] << endl;
    // }
    ll int y=0;
    for(i=n-2;i>=0;i--){
        cnt[i]+=cnt[i+1];
    }
    y=0;
    ll int ans=0;
    for(i=0;i+2<n;i++){
        y+=a[i];
        if(y==sum3){
            ans+=cnt[i+2];
        }
    }

    return ans;

}

