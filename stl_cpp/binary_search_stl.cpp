#include <bits/stdc++.h>
using namespace std;


int compare(const void* aCopy, const void* bCopy){
    const int* a = (int*)aCopy;
    const int* b = (int*)bCopy;

    if(*a < *b){
        return -1;
    }
    else if(*a > *b){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[] = {1,1,3,4,5};
    int n=5;
    vector <int> v(arr,arr+n);

    // binary search
    // only check whether element is there or not
    int binary_check_array = binary_search(arr,arr+n,8);
    int binary_check_vector = binary_search(v.begin(),v.end(),8);
    int key = 9;
    //this search will only be done using array
    int* p1 = (int*)bsearch(&key,arr , 5, sizeof(arr[0]), compare);
    if(p1){
        cout << "Element found at " << p1 - arr << endl;
    }
    else{
        cout << "Not found" << endl;
    }
    
    return 0;
}