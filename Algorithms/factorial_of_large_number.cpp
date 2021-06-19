#include <bits/stdc++.h>
using namespace std;


/*

*factorial of big numbers are very lage*
*we use array to store and multiply ans then print the array only*

*/


int multiply(int x, int res_size, int res[] ){
    int carry = 0,i;
    for(i=0;i<res_size;i++){
        int prod = res[i]*x + carry;
        res[i] = prod%10;
        carry = prod/10;
    }
    while(carry){
        res[ res_size ] = carry%10;
        carry/=10;
        res_size++;
    }
    return res_size;
}


void fact(int n){
    int i;
    int res[505];
    int res_size;
    res[0] = 1;
    res_size = 1;
    for(i=2;i<=n;i++){
        res_size = multiply(i, res_size, res );
    }
    for(i=res_size-1;i>=0; i--){
        cout << res[i];
    }
}



int main(){
    int n;
    cin >> n;
    fact(n);
    return 0;
}