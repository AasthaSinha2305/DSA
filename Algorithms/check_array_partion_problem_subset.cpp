#include <bits/stdc++.h>
using namespace std;
/*
*using dp method in o(n2)*
*not feasible with array with  big sum*
*/
bool isDiv2(int arr[], int n){
    int i,j,sum=0;
    for(i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    bool dp[(sum/2) + 1][n+1];
    for(j=0;j<=n;j++){
        dp[0][j] = true;
    }
    for(i=1;i<=(sum/2);i++){
        dp[i][0] = false;
    }
    for(i=1;i<=(sum/2);i++){
        for(j=1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(i>= arr[j-1]){
                dp[i][j] = dp[i][j] || dp[i - arr[j-1]][j-1];
                
            }
        }
    }
    // for(i=0;i<=(sum/2);i++){
    //     for(j=0;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    return dp[sum/2][n];
}


int main(){
    int arr[] = {3,1,1,2,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << isDiv2(arr,n) << endl;
    return 0;
}




/*
*faster method dp*
*/
#include <bits/stdc++.h>
using namespace std;

bool isDivIn2(int a[], int n){
    int i,j,sum=0;
    for(i=0;i<n;i++){
        sum+=a[i];
    }
    if(sum%2!=0){
        return false;
    }
    bool dp[sum/2+1];
    memset(dp,0,sizeof(dp));
    for(i=0;i<n;i++){
        for(j=sum/2;j>=a[i];j--){
            if(dp[j-a[i]]==1 || j == a[i]){
                dp[j] = true;
            }
        }
    }
    return dp[sum/2];
}


int main(){
    int arr[] = {3,1,1,2,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << isDivIn2(arr,n) << endl;
    return 0;
}

/*
*naive approach using recursion*
*/

