#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/20500
	20500 Ezreal 여눈부터 가네 ㅈㅈ
*/
using namespace std;
long long dp[1517]{ 0,0,1 };
int main() {
	fast;
	int n; cin >> n;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 1000000007;
	}
	cout << dp[n];
	return 0;
}