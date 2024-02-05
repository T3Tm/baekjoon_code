#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/15988
	15988�� 1,2,3 ���ϱ� 3
	1�� ���ϴ� ��
	2�� ���ϴ� ��
	3���� ���ϴ� ���� �ִ�.
	4���ʹ� �׷�
	1�� ���ϴ� ��Ŀ��ٰ�
	2�� ���ϴ� ��Ŀ��ٰ�
	3���� ���ϴ� ����� ���ϸ� ���� ������?

	1+3 1���� 3�� ���ؼ� 4�� ����� ����

	2+2
	1+1+2 << 2�� ���ؼ� 4�� ����� ����

	3+1
	1+1+1+1
	2+1+1
	1+2+1 << 3���� 1�� ���ϴ� ����

	dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	1+1+1
	2+1
	1+2
	3
	3�� ����� ��

	dp[1] = 1
	dp[2] = 2
	dp[3] = 4
*/
using namespace std;
long long dp[1000002];
int n, t;
int main() {
	fast; cin >> t;
	dp[1] = 1, dp[2] = 2, dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009;
	while (t--) {
		cin >> n; cout << dp[n] << endl;
	}
	return 0;
}