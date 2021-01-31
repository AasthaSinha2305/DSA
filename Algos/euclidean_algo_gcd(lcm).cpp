#include <bits/stdc++.h>
using namespace std;

//* bitwise gcd*//

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

//** Normal gcd **//

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);

}

//** Lcm **//
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}