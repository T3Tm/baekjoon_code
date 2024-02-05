#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
*	https://www.acmicpc.net/problem/9625
* 9625번 BABBA
* dp[i][j] j번째 i의 갯수
* i가 0이면 A
* i가 1이면 B
*/
using namespace std;
long long dp[2][47];
int n;
int main() {
	fast; cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[0][i] = dp[1][i - 1];
		dp[1][i] = dp[0][i - 1] + dp[1][i - 1];
	}
	cout << dp[0][n] << ' ' << dp[1][n];
	return 0;
}