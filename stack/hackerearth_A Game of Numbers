/*
input                                 output                            Next Greater     Next Smaller
8                                   1 4 4 4 -1 2 -1 -1                  3 --> 7                 7 -->1
3                                                                       7 --> 8                 8 -->4
7                                                                       1 --> 7                 7 --> 4
1                                                                       7 --> 8                 8 --> 4
7                                                                       8 --> -1                -1 --> -1
8                                                                       4 --> 5                 5 --> 2
4                                                                       5 --> -1                -1 --> -1
5                                                                       2 --> -1                -1 --> -1
2

*/
/* --------------------------------------------------------------------------- */
//General array method

#include <iostream>
using namespace std;
int main(){
    long long int n,r;
    cin >> n;
    long long int a[n],b[n],i,j,k,y,w,rr,ww;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n;i++){
        b[i] = 0;
    }
    r=0;
    for(i=0;i<n;i++){
          if(i==n-1){
            b[r] = -1;
            r++;
          }
          else{
              rr=0;
        for(j=i+1;i<n;j++){
            rr++;
            if(a[j] > a[i]){
                if(j==n-1){
                     b[r] = -1;
                     r++;
                     break;
                     }
                ww=0;
                for(k=j+1;k<n;k++){
                    ww++;
                  if(a[k] < a[j]){
                        b[r] = a[k];
                        r++;
                       // cout << "-" << i<< endl;
                        break;
                    }
                    if(ww== (n-j-1)){
                        b[r]=-1;
                        r++;
                    }
                }
                break;
            }
            if(rr == (n-i-1)){
                b[r]=-1;
                r++;
            }
        }

          }
    }

    for(i=0;i<r;i++){
        cout << b[i] << " ";
    }
    return 0;
}

/* ------------------------------------------------------------------------------------- */
//STACK METHOD


#include <bits/stdc++.h>
using namespace std;
long long int top = -1;
void push(long long int s[], long long int x, long long int n){
    if(top == n-1){
        cout << "Stack is full" << endl;
    }
    else{
        top++;
        s[top] = x;
    }
}
int isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}
void pop(){
    if(isEmpty()){
        cout << "Already Empty" << endl;
    }
    else{
        top--;
    }
}

int main()
{
    long long int n,e,i,r,rr,j,ww,k;
    cin >> n;
    long long int stack[n],a[n],b[n];
    for(i=0;i<n;i++){
        cin >> e;
        push(stack,e,n);
    }
        for(i=0;i<n;i++){
        b[i] = 0;
    }
    r=0;
    for(i=0;i<n;i++){
          if(i==n-1){
            b[r] = -1;
            r++;
          }
          else{
              rr=0;
        for(j=i+1;i<n;j++){
            rr++;
            if(stack[j] > stack[i]){
                if(j==n-1){
                     b[r] = -1;
                     r++;
                     break;
                     }
                ww=0;
                for(k=j+1;k<n;k++){
                    ww++;
                  if(stack[k] < stack[j]){
                        b[r] = stack[k];
                        r++;
                       // cout << "-" << i<< endl;
                        break;
                    }
                    if(ww== (n-j-1)){
                        b[r]=-1;
                        r++;
                    }
                }
                break;
            }
            if(rr == (n-i-1)){
                b[r]=-1;
                r++;
            }
        }

          }
    }

    for(i=0;i<r;i++){
        cout << b[i] << " ";
    }


	return 0;
}


