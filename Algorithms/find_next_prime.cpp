#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isPrime(ll int n){
    if(n<=1){
        return false;
    }
    if(n<=3){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }
    ll int i;
    for(i=5;i*i<n;i+=6){
        if(n%i==0 && n%(i+1)==0){
            return false;
        }
    }
    return true;
}

ll int nextPrime(ll int n){
    if(n<=1){
        return 2;
    }
    ll int primeN = n;
    bool found = false;

    while(!found){
        primeN++;
        if(isPrime(primeN)){
            found = true;
        }
    }
    return primeN;
}

// int main()
// {
//     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
//     ll int t, n, i, j;
//     // cin >> t;
//     // while (t--) {
//     //     cin >> n;
//     // }
//     cout << (nextPrime(5)) << endl;
//     return 0;
// }