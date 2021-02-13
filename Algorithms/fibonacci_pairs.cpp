#include <bits/stdc++.h>
#include <bits/stl_pair.h>
using namespace std;

//** fast method using stl pairs **//

//** Access first elemnt with fib(n).first & second element with fib(n).second **//

pair<int, int> fib (int n) {
    if (n == 0){
        return make_pair(0,1);
    }
        // return {0, 1};

    pair<int, int> p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1){
        return make_pair(d,c+d);
    }
        // return {d, c + d};
    else{
        return make_pair(c,d);
    }
        // return {c, d};
}

//** Normal way to find fibonacci series using recursion **//

int fib2(int n)
{
    if (n <= 1){
        return n;
    }
    return fib2(n-1) + fib2(n-2);
}

//** Normal way using array **//

int fib3(int n)
{
    int f[n + 2]; 
    int i;

    f[0] = 0;
    f[1] = 1;
 
    for(i = 2; i <= n; i++)
    {
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}
