#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N) 
int trap(int arr[], int n)
{
    int left[n];
    int right[n];

    left[0] = arr[0];
    for(int i=1;i<n;i++){
        left[i] = max(left[i-1],arr[i]);
    }

    right[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--){
        right[i] = max(right[i+1],arr[i]);
    }

    int ans = 0;
    for(int i=0;i<n;i++){
        ans += min(left[i],right[i]) - arr[i];
    }
  
    return ans;
}
 
int main(void)
{
    int heights[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
    int n = sizeof(heights) / sizeof(heights[0]);
 
    cout<<"Maximum height of water : "<<trap(heights,n);
 
    return 0;
}