#include <bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int row, int col, int n){
    for(int i=0; i<row; i++){
        if(board[i][col]==1){
            return false;
        }
    }
    int x = row;
    int y = col;
    while(x>=0 && y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;
    while(x>=0 && y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;

}

bool solveNQueen(int board[][10], int row, int n){
    if(row == n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    cout << "Q ";
                }
                else{
                    cout << "_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }
    for(int j=0;j<n;j++){
        if(isSafe(board,row,j,n)){
            board[row][j]=1;
            bool nextQueen = solveNQueen(board,row+1, n);
            if(nextQueen){
                return true;
            }
            board[row][j]= 0;
        }

    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int board[10][10];
    memset(board,0,sizeof(board));
    solveNQueen(board,0,n);
    return 0;
}