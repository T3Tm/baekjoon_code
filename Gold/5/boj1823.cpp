#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1823
	1823번 수확
	
	
	arr[i:j]제외한 합
*/
using namespace std;
int n;
vector<int>arr;
long long dp[2002][2002];
void solve() {
	for (int i = 1; i <= n; i++)dp[i][i] = arr[i] * n;
	for (int y = 1; y <=n; y++) {//i번째 고른 것 i-1에서 그럼 고른 것에서 i에 고른 것에 더할 수 있음.
		for (int x = y-1; x >= 1; x--) {
			dp[x][y] = max(dp[x+1][y] +arr[x]*(n-(y-x)), dp[x][y-1] + arr[y] * (n - (y-x)));
		}
	}
	cout << dp[1][n];
}
int main() {
	fast;
	cin >> n; arr.resize(n+1);
	for (int i = 1; i <= n; i++)cin >> arr[i];
	solve();
	return 0;
}