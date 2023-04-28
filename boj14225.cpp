#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14225
	14225번 부분수열의 합
*/
using namespace std;
int n,arr[22];
bool bit[2000002];
void getNum(int depth, int result) {
	if (depth == n) {
		bit[result] = 1;
		return;
	}
	getNum(depth + 1, result + arr[depth]);
	getNum(depth + 1, result);
}
void solve() {
	getNum(0, 0);
	for (int i = 1; i <= 2000000; i++) {
		if (!bit[i]) {
			cout << i;
			break;
		}
	}
}
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	solve();
	return 0;
}