#include <bits/stdc++.h>
using namespace std;
#define ll long long


/*
*note -- lis can also be made by using lcs dp method, just you dont have to take repeated elements (use set)*
*/


int lis_main(int arr[], int n,int* max_ref ){
    if( n==1){
        return 1;
    }
    int res, max_ending_here = 1;
    for(int i=1;i<n;i++){
        res = lis_main(arr,i,max_ref);
        if(  (arr[i-1] < arr[n-1] ) && (res+1 > max_ending_here ) ){
            max_ending_here = res + 1;
        }
    }
    if(*max_ref < max_ending_here ){
        *max_ref = max_ending_here;
    }
    return max_ending_here;
}


int lis_fun(int arr[], int n  ){
    int max = 1;
    lis_main(arr, n, &max);

    return max;
}

int lis_fun_dp(int arr[], int n ){
    int lis[n];
    lis[0] = 1;
    int i,j;
    for(i=1;i<n;i++){
        lis[i] = 1;
        for(j=0;j<i;j++){
            if( arr[j] < arr[i]  && lis[i] < lis[j]+1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element( lis, lis+n );
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]); // simply n;
    cout << lis_fun(arr,n) << endl;
    cout << lis_fun_dp(arr,n) << endl;
    return 0;
}