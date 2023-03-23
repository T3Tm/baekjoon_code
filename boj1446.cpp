#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/1446
	1446번 지름길

	D킬로미터 길이의 고속도로를 지난다.
	지름길 있음.
	일방통행이다.

	해당하는 위치까지 최솟 거리를 계산한다.
	예를 들어)
	0 50 10
	0 50 20 이면
	50까지는 10이면 갈 수 있다.
	50 100  < 100까지는 20이면 갈 수 있다.
	0~50 3
	0~49 1
	49~50 1 => 총 2 50에 도달하는데 2면 갈 수 있음.
	도달하는 곳이 어떻게 되는지가 중요한듯

*/
using namespace std;
int n, d;//지름길 갯수 ,도로의 길이
int arr[10002];
int dp[10002];
map<int, map<int, int>>highpass;
int main() {//해당하는 최소에 
	fast;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		int a, b, c;//시작 ,끝,길이
		cin >> a >> b >> c;
		if (highpass.find(b) != highpass.end() && highpass[b].find(a) != highpass[b].end()) {
			highpass[b][a] = min(highpass[b][a], c);
		}
		else {
			highpass[b][a] = c;
		}
	}
	for (int i = 1; i <= d; i++) {
		if (highpass.find(i) != highpass.end()) {//지름길 있음
			for (auto& value : highpass[i]) {
				if (dp[i] != 0) {
					dp[i] = min({ dp[i],dp[i - 1] + 1, dp[value.first] + value.second });
				}
				else {
					dp[i] = min(dp[i - 1] + 1, dp[value.first] + value.second);
				}

			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	cout << dp[d];
	return 0;
}