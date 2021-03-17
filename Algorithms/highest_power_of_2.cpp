#include <bits/stdc++.h>
using namespace std;

//** for finding the greatest power of 2 in a number **//


int highestPower2(int n){
    int counti=0;
    while(n >>= 1){
        counti++;
    }
    return pow(2,counti); 
}

