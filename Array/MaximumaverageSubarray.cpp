#include<bits/stdc++.h>
using namespace std;


int subarray_average_sum(int arr[], int n,int k){
    int mini = INT_MAX;
    for(int i=0;i<=n-k;i++){
        int sum = 0;
        for(int j=i;j<i+k;j++){
            sum +=arr[j];
        }

        mini = min(sum,mini);
    }
    return mini;
}
int main(){

    int n ;
    int arr[] =  {3, 7, 90, 20, 10, 50, 40};
    n = sizeof(arr)/sizeof(int);
 
    int k = 3;
    int ans = subarray_average_sum(arr,n,k);
    cout<<"\n";
    float avg = ans/k;
    cout<<avg<<endl;

    return 0;

}