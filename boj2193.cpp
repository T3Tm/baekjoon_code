#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2193
	2193번 이친수
	결론 0으로 끝나는 것은 2배가 되고
	0으로 끝나지 않는 것은 1배가 된다.
	1
	2자리 이친수
	10 1개
	3자리 이친수는?
	101
	100 2개 있다.
	4자리 이친수는?
	1010
	1001
	1000 3개
	5자리 이친수는?

*/
using namespace std;
long long n, dp[2][92];
int main() {
	fast; cin >> n;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[1][i] = dp[0][i - 1];//1에서는 0을 붙여야한다.
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];//그전에 1에서 0을 붙이면 그 다음 숫자의 갯수
	}
	cout << dp[1][n] + dp[0][n];
	return 0;
}