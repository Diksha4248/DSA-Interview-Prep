#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=Z5AEc12ieOs

// A celebrity is a person who is known to all but does not know anyone at a party.If you go to a party of N people, find if there is a celebrity in the party or not.
// A square N*N matrix M[][] is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person.
// Here M[i][j] will always be 0

// Note : Follow 0 based indexing


// Approach 1
// TC : O(N*N)
// SC: O(N)
int celebrity(vector <vector <int>> &M,int n){
    int in[n] = {0}; //indegree
    int out[n] = {0}; //outdegree

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(M[i][j]==1){
                in[j]++;
                out[i]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(in[i]==n-1 and out[i]==0){
            return i;
        }
    }

    return -1;
}

// Approach 2
// TC: O(N)
// SC: O(1)

int celebre(vector <vector<int>> &M, int n){
    int c = 0;
    for(int i=0;i<n;i++){
        if(M[c][i]==1){
            c = i;
        }
    }

    for(int i=0;i<n;i++){
        if(i!=c and (M[c][i]==1 or  M[i][c]==0)){
            return -1;
        }
    }

    return c;
}
int main(){
    int n = 3;
    vector <vector <int>> M = {{0, 1 ,0},
                               {0, 0 ,0},
                               {0, 1 ,0}};

    // int ans = celebrity(M,n);
    int ans = celebre(M,n);
    if(ans!=-1)
        cout<<"The celebrity is : "<<ans<<"th element";
    else 
        cout<<"\nThere is no celebrity"<<endl;    

    return 0;
}