#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define n 5
#define m 5
// TO FIND THE SUM OF SUBMATIX IN LINEAR TIME USING SUBMATRIX USING QUERIES

int preProcess(int mat[m][n], int aux[m][n]){
    for(int j = 0; j < n; j++){
        aux[0][j] = mat[0][j];
    }

    for(int i=1 ;i <m; i++){
        for(int j= 0; j <n; j++){
            aux[i][j] = mat[i][j] + aux[i-1][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            aux[i][j]+=aux[i][j-1];
        }
    }
}
int sumQuery(int aux[n][m], int x1, int y1, int x2, int y2 ){
    int res = aux[x2][y2];

    if(x1 > 0){
        res-=(aux[x1-1][y2]);
    }
    if(y1 > 0){
        res-=(aux[x2][y1-1]);
    }
    if(x1 > 0  && y1 > 0){
        res+=(aux[x1-1][y1-1]);
    }
    return res;
}

// int main()
// {
//     ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

//     int arr[m][n] = {     
//         {1,2,3,4,5},
//         {1,2,3,4,5},
//         {1,2,3,4,5},
//         {1,2,3,4,5},
//         {1,2,3,4,5}
//     };
//     int aux[m][n];
//     preProcess(arr,aux);
//     cout << sumQuery(aux,1,1,1,1);
//     return 0;
// }