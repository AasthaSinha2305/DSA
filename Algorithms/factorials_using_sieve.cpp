#include <bits/stdc++.h>
using namespace std;

// to find the factors using seive easily
#define MAX 5000
bool vis[MAX];
vector<int> primes;

int findFactorial(int n){
    int ans = 0;
    for(auto x: primes){
        while(n%x==0){
            ans++;
            n/=x;
        }
    }
    if(n>1){
        ans++;
    }
    return ans;
}

void sieve(int n){
    int i,j;
    for(i=2;i*i<=n;i++){
        if(!vis[i]){
            for(j=i*i;j<=n;j+=i){
                vis[j] = 1;
            }
        }
    }
    for(i=2;i<=n;i++){
        if(!vis[i]){
            primes.push_back(i);
        }
    }

}


// to find the factors using normal brute force method

int findFactors_bf( int n ){
    int ans = 0;
    while(n%2==0){
        n/=2;
        ans++;
    }
    for(int i=3;i<=n;i+=2){
        while(n%i==0){
            ans++;
            n/=i;
        }
    }
    if(n>2){
        ans++;
    }
    return ans;
}


int main( ){
    int n;
    cin >> n;
    sieve(n);
    cout << findFactorial(n) << endl;
    cout << findFactors_bf(n) << endl;
    return 0;
}