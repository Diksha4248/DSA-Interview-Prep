#include<bits/stdc++.h>
using namespace std;


// TC : O(N^3)  (near about N^3 not exactly, as loop running from i won't exactly run for N times always )
// SC : O(1)
int brute(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<j;k++){
                sum += arr[k];
                maxi = max(sum,maxi);
            }
        }
    }
    return maxi;
}

// TC : O(N^2)
// SC : O(1)
int brute_optimised(int arr[],int n){
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            maxi = max(sum,maxi);
        }
    }
    return maxi;
}

// TC : O(N)
// SC : O(1)
int kadane(int arr[], int n){
    int sum  = 0;
    int maxi = INT_MIN;
    int start;
    int ansStart, ansEnd  = -1;
    for(int i=0;i<n;i++){
        if(sum == 0) start = i;
        sum +=arr[i];

        if(sum > maxi){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }

    for(int i=ansStart;i<=ansEnd;i++){
        cout<<arr[i]<<" ";
        }

    if(maxi < 0) maxi = 0;   // if all negatives, simply return 0 as the ans
    return maxi;
}
int main(){

    int n ;
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    n = sizeof(arr)/sizeof(int);
 
    int ans = kadane(arr,n);
    cout<<"\n";
    cout<<ans<<endl;

    return 0;

}