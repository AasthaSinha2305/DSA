#include <bits/stdc++.h>
using namespace std;

//* recursive method *//

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

//* Faster bitwise method*//

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

//** using moadulo **//

#define N 1000000007;
  
long long int exponentiation(long long int base, long long int exp) 
{ 
    long long int t = 1; 
    while (exp > 0)  
    { 
  
        // for cases where exponent 
        // is not an even value 
        if (exp % 2 != 0) 
            t = (t * base) % N; 
  
        base = (base * base) % N; 
        exp /= 2; 
    } 
    return t % N; 
}