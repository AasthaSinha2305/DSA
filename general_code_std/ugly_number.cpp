#include <bits/stdc++.h>
using namespace std;


/*  
  *using dp*
 */
int uglyNo(int n){
    int next_multiple_2 = 2;
    int next_multiple_3 = 3;
    int next_multiple_5 = 5;
    int next_ugly_no = 1;
    int ugly_arr[n];
    ugly_arr[0] = 1;
    int i2 =0;
    int  i3 = 0;
    int i5 = 0;
    for(int i=1; i<n; i++){
        next_ugly_no = min( min( next_multiple_2,next_multiple_3 ),  next_multiple_5 );
        ugly_arr[i] = next_ugly_no;
        if(next_ugly_no == next_multiple_2){
            i2++;
            next_multiple_2 = ugly_arr[i2]*2;
        }
        if(next_ugly_no == next_multiple_3){
            i3++;
            next_multiple_3 = ugly_arr[i3]*3;
        }
        if(next_ugly_no == next_multiple_5){
            i5++;
            next_multiple_5 = ugly_arr[i5]*5;
        }
    }
    return next_ugly_no;
}



/*
*using simple brute force*
*/

int divideMax(int num, int den){
    while(num%den == 0){
        num/=den;
    }
    return num;
}

bool isUgly(int n){
    n = divideMax(n,2);
    n = divideMax(n,3);
    n = divideMax(n,5);
    return (n==1) ? 1 : 0 ;
} 



int uglyNo(int n){
    int i = 1;
    int count = 1;
    while( count < n){
        i++;
        if(isUgly(i)){
            count++;
        }
    }
    return i;
}


/*
*using set data structure ans the simplest approch*
*/

int uglyNo(int n){
    if(n==1 or n==2 or n==3 or n==4 or n==5 ){
        return n;
    }   
    set <int> s;
    s.insert(1);
    n--;
    while(n){
        auto it = s.begin();
        int x = *it;
        s.erase(it);
        s.insert(x*2);
        s.insert(x*3);
        s.insert(x*5);
        n--;
    }
    return *(s.begin());
}


int main(){
    // clock_t begin,end;
    // double time_spent;
    // begin = clock();
    int n = uglyNo(150);
    // end = clock();
    // time_spent = (double)(end - begin) /CLOCKS_PER_SEC;
    // cout << " ---- " << time_spent << endl;
    cout << n << endl;
    return 0;
}


// 1 2 3 4 5 6 8 9 10