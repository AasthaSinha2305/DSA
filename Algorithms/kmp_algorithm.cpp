#include <bits/stdc++.h>
using namespace std;


void computeLPS(string pat, int lps[], int pl){
    int len = 0;
    lps[0] = 0;
    int i= 1;
    while(i<pl){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}


void kmp(string pat, string txt){
    int pl = pat.length();
    int tl = txt.length();

    int lps[pl];

    computeLPS(pat, lps, pl);
    int i = 0;
    int j = 0;
    while(i<tl){
        if(pat[j] == txt[i]){
            i++;
            j++;
        }
        if(j==pl){
            cout << "found at " << i - j << endl;
            j = lps[j-1];
        }
        else if(i<tl && pat[j] != txt[i]){
            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char txt[] = "ABABDABACDABABCABAB";
    char pat[] = "ABABCABAB";
    kmp(pat, txt);
    return 0;
}