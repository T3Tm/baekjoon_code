#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/12852
	12852번 1로 만들기 2

	1. x가 3으로 나눠 떨어지면 3으로 나눈다.
	2. x가 2로 나누어 떨어지면 2로 나눈다.
	3. 1을 뺀다.

	기존의 1,3이랑 다른 것은 전에 왔던 곳을 좌표로 찍어야 되네?
	이러면 바뀔 때 그냥 그 좌표로 넣어주면 된다.
*/
using namespace std;
int n;
struct myarr {
	long long num;
	int pre;
};
myarr dp[1000002];
int main() {
	fast; cin >> n;
	dp[0] = { 0,-1 };
	dp[1] = { 0,0 };
	dp[2] = { 1,1 };
	dp[3] = { 1,1 };
	for (int i = 4; i <= n; i++) {
		dp[i].num = dp[i - 1].num + 1;
		dp[i].pre = i - 1;
		if (i % 2 == 0 && dp[i].num > dp[i / 2].num + 1) {
			dp[i] = { dp[i / 2].num + 1,i / 2 };
		}
		if (i % 3 == 0 && dp[i].num > dp[i / 3].num + 1) {
			dp[i] = { dp[i / 3].num + 1,i / 3 };
		}
	}
	cout << dp[n].num << endl;
	int start = n;
	while (dp[start].pre != -1) {
		cout << start << ' ';
		start = dp[start].pre;
	}
	return 0;
}