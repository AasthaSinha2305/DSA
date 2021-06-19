#include <bits/stdc++.h>
using namespace std;

//** for finding the greatest power of 2 in a number **//



int hp( int n ){
    if( n < 0 ){
        return 0;
    }
    int res = 1;
    for(int i = 1; i<=31; i++ ){
        int curr_res = 1 << i;
        if( curr_res > n ){
            break;
        }
        res = curr_res;
    }
    return res;
}

int highestPower2(int n){
    int counti=0;
    while(n >>= 1){
        counti++;
    }
    return pow(2,counti); 
}


int main() {
    int n,t;
    cin >> t;
    
    while(t--){
        cin >> n;
        cout << hp( n ) << endl;
    }
}

