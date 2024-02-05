#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/2293
	2293번 동전 1

	사용한 동전의 구성이 같은데 순서만 다르면 같은 경우 < 즉 조합이다 라는 것.

	n개의 줄에 동전의 가치가 주어짐.
	동전의 가치는 10만보다 작음.
	각 동전을 이용해서 k원을 만들 수 있니? 라는 문제.
	예를 들어
	근데 구성이 같다면 배치하는 것들은 다 같은 것이다.

	n원을 만들 때 경우의 수

	dp[n] = dp[n] + dp[i-arr[j]] 이다.
*/
using namespace std;
int dp[10002] = { 1 }, n, k;
int arr[102];
int main() {
	fast; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= k; i++) {
			if (i < arr[j])continue;
			dp[i] += dp[i - arr[j]];
		}
	}
	cout << dp[k];
	return 0;
}