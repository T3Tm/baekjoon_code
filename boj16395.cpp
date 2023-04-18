#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16395
	16395번 파스칼의 삼각형

	1. N번째 행에는 N개의 수가 있다.
	2. 첫 번쨰 행은 1이다.
	dp[i][j] 파스칼의 삼각형
	iCj 이라고 하자.

	dp[i][j]
	j==1 || j==i일때는 1로 초기화
	아닐 때는 dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; 이다.
*/
using namespace std;
int n, k;
long long dp[32][32];
int main() {
	fast; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i)dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cout << dp[n][k];
	return 0;
}