#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16395
	16395�� �Ľ�Į�� �ﰢ��

	1. N��° �࿡�� N���� ���� �ִ�.
	2. ù ���� ���� 1�̴�.
	dp[i][j] �Ľ�Į�� �ﰢ��
	iCj �̶�� ����.

	dp[i][j]
	j==1 || j==i�϶��� 1�� �ʱ�ȭ
	�ƴ� ���� dp[i][j] = dp[i-1][j-1] + dp[i-1][j]; �̴�.
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