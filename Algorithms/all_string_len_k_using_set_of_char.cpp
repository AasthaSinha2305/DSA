#include <bits/stdc++.h>
using namespace std;



void printAllKLengthRec(vector<char> set1,string prefix, int n , int k, vector <string> &v1){
    if(k==0){
        // cout << prefix << endl;
        v1.push_back(prefix);
        return;
    }
    for(int i=0; i<n; i++){
        string newPrefix;
        newPrefix = prefix + set1[i];
        printAllKLengthRec(set1, newPrefix, n , k-1, v1);
    }
}

vector <string> printAllKLength(vector<char> set1, int k, int n){
    vector<string> v;
    printAllKLengthRec(set1,"",n, k, v);
    return v;
}



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, n, i, j;
    int k = 2;
    // char set1[] = {'a', 'g'};
    vector <char> vc;
    vc.push_back('a');
    vc.push_back('b');
    vector<string> v = printAllKLength(vc, k, 2);
    for(auto w: v){
        cout << w << endl;
    }
    return 0;
}