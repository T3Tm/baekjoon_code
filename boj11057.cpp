#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11057
	11057번 오르막 수

	오르막 수는 수의 자리가 오름차순으로 이루는 수
	인접한 수가 같아도 오름차순이다.

	N이 주어졌을때 길이가 N인 오르막 수의 개수는?

	dp[n][number] = dp[n-1][number:10]이다.
	수는 0으로 시작할 수 있다.
*/
using namespace std;
int n;
int dp[1002][11];
int main() {
	fast; cin >> n;
	for (int i = 0; i <= 9; i++) dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {//
			for (int z = j; z <= 9; z++) {
				dp[i][j] = (dp[i][j] + dp[i - 1][z]) % 10007;
			}
		}
	}
	long long answer = 0;
	for (int i = 0; i <= 9; i++) {
		answer += dp[n][i];
	}
	cout << answer % 10007;
	return 0;
}