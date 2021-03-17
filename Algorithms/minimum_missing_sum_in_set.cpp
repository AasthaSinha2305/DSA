#include <bits/stdc++.h>
using namespace std;

//**  returns minimum number that cannot be expressed as a sum of any elements of the set or array  **//

ll int checkMissing(int arr[], int n){
    ll int res = 1,i;
    for(i=0; i<n && a[i] <= res; i++){
        res = res + a[i];
    }
    return res;
}

