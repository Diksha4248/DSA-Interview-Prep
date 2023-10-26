#include <bits/stdc++.h>
using namespace std;

// TC : O(N*M)
// SC : O(N*M)
vector <int> spiral(vector <vector <int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector <int> ans;

    while(top<=bottom and left<=right){
    // right
    for(int i=left ;i<=right ;i++){
        ans.push_back(mat[top][i]);
    }
    top++;
    for(int i=top;i<=bottom;i++){
        ans.push_back(mat[i][right]);
    }
    right--;
    if(top<=bottom){
        for(int i=right;i>=left;i--){
        ans.push_back(mat[bottom][i]);
        }
        bottom--;
    }
    for(int i=bottom;i>=top;i--){
        ans.push_back(mat[i][left]);
    }
    left++;
}

     return ans;
}

int main(){

      vector <vector<int>> mat = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};

        vector <int> ans = spiral(mat);  
        int n = ans.size();
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }       

    return 0;
}