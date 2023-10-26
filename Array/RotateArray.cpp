#include <bits/stdc++.h>
using namespace std;

// TC : O(N)
// SC : O(N)
void rotate(int arr[],int n,int d){

    int temp[n];
    int k = 0; // to keep track of current index
    for(int i=d;i<n;i++){
        temp[k] = arr[i];
        k++;
    }

    for(int i=0;i<d;i++){
        temp[k] = arr[i];
        k++;
    }

    for(int i=0;i<n;i++){
        cout<<temp[i]<<" ";
    }
}


// TC = O(N) 
// SC = O(1)
void rotate_optimised(int arr[],int n,int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){

    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);
    int d =3;

    rotate_optimised(arr,n,d);
    return 0;
}