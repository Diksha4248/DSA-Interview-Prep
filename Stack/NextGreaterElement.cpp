#include <bits/stdc++.h>
using namespace std;

//striver : https://www.youtube.com/watch?v=Du881K7Jtk8

// Approach 1
// TC: O(N*N)
// SC : O(1)

void nextGreater(int arr[],int n){
   
    for(int i=0;i<n;i++){
        int nextg = -1;
        int curr = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]>curr){
                nextg = arr[j];
                break;
            }
        }
        cout<<curr<<"->"<<nextg<<"\n";
    }
}

// Approach 2
// TC: O(N)

void nge(int arr[], int n)
{
    stack<int> s;
    s.push(arr[0]);
 
    for (int i = 1; i < n; i++) {
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && s.top() < arr[i]) {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
 
    while (s.empty() == false) {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

int main(){
    int n = 4;
    int arr[] = {4,5,2 ,25};

    // nextGreater(arr,n);
    nge(arr,n);
    return 0;
}