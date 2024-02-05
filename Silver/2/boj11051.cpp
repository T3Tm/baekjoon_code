#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11051
	11051번 이항 계수 2
*/
using namespace std;
int n, k;
int dp[1002][1002];
int main() {
	fast; cin >> n >> k;
	//5C2 구해봐라 N이 다만 1000까지 간다라는 거네?
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) dp[i][j] = 1;
			else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k];
	return 0;
}