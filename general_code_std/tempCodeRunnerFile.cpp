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