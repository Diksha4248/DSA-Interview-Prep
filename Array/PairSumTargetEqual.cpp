
#include <bits/stdc++.h>
using namespace std;

// TC : O(N^2)
// SC : O(1)
vector<pair<int, int>> getPairsCount(int arr[], int n, int K)
{
    vector<pair<int, int>> pairs;
    int count = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] + arr[j] == K){
				count++;
                pairs.push_back(make_pair(arr[i], arr[j]));
            }
	return pairs;
}


int main()
{
	int arr[] = { 1, 5, 7, -1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int K = 6;
    vector<pair<int, int>> result = getPairsCount(arr,n,K);
    int count = result.size();
    for(auto x:result){
        cout<<x.first<<" "<<x.second<<endl;
    }
	cout << "\nCount of pairs is "<<count;
	return 0;
}


