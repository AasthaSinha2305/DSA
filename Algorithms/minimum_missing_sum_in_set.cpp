#include <bits/stdc++.h>
using namespace std;
#define ll long long

//**  returns minimum number that cannot be expressed as a sum of any elements of the set or array  **//

ll int checkMissing(int arr[], int n){
    ll int res = 1,i;
    for(i=0; i<n && arr[i] <= res; i++){
        res = res + arr[i];
    }
    return res;
}

