#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int arr[] = {1,1,3, 3,4,4,5,6,7,4,5};
    int n = 11;
    vector <int> v(arr,arr+n);

    // to reverse a vector 
    reverse(v.begin(),v.end());

    //maximum element
    int d = *min_element(v.begin(),v.end());

    // maximum element
    int e = *max_element(v.begin(),v.end());
    
    //to find sum of vector
    int sum = accumulate(v.begin(),v.end(),0); 

    //count occurence of a number
    int frq = count(v.begin(),v.end(),1);

    //finding an element
    int pos = find(v.begin(),v.end(),4) - v.begin();

    //return pointer to the element equal or greater
    int ind = lower_bound(arr,arr+n,2) - arr;
    int ind1 = lower_bound(v.begin(),v.end(),3) - v.begin();

    //returns pointer to the index greater than
    int ind2 = upper_bound(arr,arr+n, 3) - arr;
    int ind3 = upper_bound(v.begin(),v.end(),3) - v.begin();

/* 
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
*/
    //deletes a particular index of a vector
    v.erase(v.begin()+1);

    //to deletes duplicates in the vector
    //first sort the vector
    sort(v.begin(),v.end());
    // v.erase(unique(v.begin(),v.end()),v.end());

    //find next permulation of a vector if possible
    next_permutation(v.begin(),v.end());

    // find prev permulation of a vector if possible
    prev_permutation(v.begin(),v.end());

/*
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << endl;
*/  
    int g =distance(v.begin(),max_element(v.begin(),v.end()));

    cout << g << endl; 
    return 0;
}