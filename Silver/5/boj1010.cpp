#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1010
	1010번 다리 놓기

	다리 끼리 겹칠 수 없다.
	그러면
	a<b<c<d 이런 느낌이다.
	a,b,c,d는 이미 자리가 정해져 있으므로
	mCn이면 될 것 같은데?
*/
using namespace std;
int t;
long long dp[32][32];
int main() {
	fast; cin >> t;
	for (int i = 1; i <= 29; i++) {//1C1 = 1 2C1 2C2
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i)dp[i][j] = 1;
			else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}
	while (t--) {
		int n, m; cin >> n >> m;
		cout << dp[m][n] << endl;
	}
	return 0;
}