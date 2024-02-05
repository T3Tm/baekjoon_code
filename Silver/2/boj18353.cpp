#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/18353
	병사 배치하기



	front fight > back fight

*/
using namespace std;
vector<int>arr;
vector<int>dp;
int main() {
	fast;
	int n;
	cin >> n;
	arr.resize(n);
	dp.assign(n, 1);
	int total = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[i]) {
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		total = max(total, dp[i]);
	}
	cout << n - total;
	return 0;
}