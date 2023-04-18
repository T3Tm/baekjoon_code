#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/15988
	15988번 1,2,3 더하기 3
	1로 더하는 것
	2로 더하는 것
	3으로 더하는 것이 있다.
	4부터는 그럼
	1로 더하는 방식에다가
	2로 더하는 방식에다가
	3으로 더하는 방식을 더하면 되지 않을까?

	1+3 1에서 3을 더해서 4를 만드는 순간

	2+2
	1+1+2 << 2를 더해서 4를 만드는 순간

	3+1
	1+1+1+1
	2+1+1
	1+2+1 << 3에서 1을 더하는 순간

	dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

	1+1+1
	2+1
	1+2
	3
	3을 만드는 것

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