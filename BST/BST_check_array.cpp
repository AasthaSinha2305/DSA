#include <bits/stdc++.h>
using namespace std;
int arr(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}
int checkbst(int a[],int n){
    int i;
    int maxi = INT_MAX;
    int mini = INT_MIN;
    bool flag = true;
    for(i=1;i<n;i++){
        if(a[i]>a[i-1] && a[i]>INT_MIN && a[i]<INT_MAX){
            mini = a[i-1];
        }
        else if(a[i]<a[i-1] && a[i]>INT_MIN && a[i] <INT_MAX){
            maxi = a[i-1];
        }
        else{
            flag = false;
            break;
        }
    }
    if(flag == false){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}

int main() {

	// your code goes here11
	int tc,n;
	cin >> tc;
	while(tc--){
	    cin >> n;
        int a[n],i;
	    for(i=0;i<n;i++){
	        cin >> a[i];
	    }
        //arrange in accending order before checking for bst
	    qsort(a,n,sizeof(int),arr);
	    checkbst(a,n);
	}
	return 0;
}
