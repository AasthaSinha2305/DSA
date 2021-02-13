#include <bits/stdc++.h>
#include <bits/stl_vector.h>
using namespace std;

//** checking  a number is prime or not **//

//** marking untill n **//

int checkPrime(int n){
    vector<int> is_prime(n+1, 1);
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
            is_prime[j] = 0;
        }
    }
    return is_prime[n];
}

//**  count the number of primes **//

int count_primes(int n) {
    const int S = 10000;

    vector<int> primes;
    vector<int>::iterator itr;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);
    for (int i = 2; i <= nsqrt; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; k++) {
        fill(block.begin(), block.end(), true);
        int start = k * S;
        for (itr = primes.begin();itr!=primes.end();itr++) {
            int start_idx = (start + *itr - 1) / *itr;
            int j = max(start_idx, *itr) * (*itr) - start;
            for (; j < S; j += (*itr))
                block[j] = false;
        }
        if (k == 0)
            block[0] = block[1] = false;
        for (int i = 0; i < S && start + i <= n; i++) {
            if (block[i])
                result++;
        }
    }
    return result;
}

