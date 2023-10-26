#include <bits/stdc++.h>
using namespace std;

//https://www.youtube.com/watch?v=VS0BcOiKaGI

// TC: O(N^2)
// SC : O(1)
bool find(int mat[4][4], int n, int ele){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == ele) return true;
        }
    }

    return false;
}

// TC : O(N+M) N = no of columns and m = no of rows
// SC : O(1)
bool find_optimised(int mat[4][4],int n, int ele){
    int i=0;
    int j=n-1;
 
    while(i>=0 and i<n and j>=0 and j<n){
        if(mat[i][j]==ele){
            return true;
        }

        else if(mat[i][j] > ele){
            j--;
        }

        else{
            i++;
        }
    }
    return false;
}


int main(){

    int n = 4;
    int mat[4][4] = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};

    int ele = 23;
    int ans =  find_optimised(mat, n, ele);
    if(ans) cout<<"Element Found";
    else cout<<"Element not found" ;              
    return 0;
}