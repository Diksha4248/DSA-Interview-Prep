#include <bits/stdc++.h>
using namespace std;


// optimised
// TC : O(N)
// SC : O(1)
vector <int> duplicates(int arr[],int n){
    vector <int> ans;

    for(int i=0;i<n;i++){
        int index  = arr[i]%n;
        arr[index]+= n;
    }

     for(int i=0;i<n;i++){
        if(arr[i]/n >= 2){
            ans.push_back(i);
        }
     }

     if(ans.size() == 0) return {-1};
     else return ans;
}




int main(){

    int arr[] = {1,2,3,4,5,5,6,7,7,9,9,9,9};
    int n = sizeof(arr)/sizeof(int);

    // unordered_map <int,int> mp;
    // for(int i=0;i<n;i++){
    //     mp[arr[i]]++;
    // }

    // for(auto x:mp){
    //     if(x.second >=2) cout<<x.first<<" ";
    // }

    vector <int> ans = duplicates(arr,n);
    for(auto x: ans){
        cout<<x<<" ";
    }

}