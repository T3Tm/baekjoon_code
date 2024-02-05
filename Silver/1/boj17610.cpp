#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17610
	17610¹ø ¾çÆÈÀú¿ï
*/
using namespace std;
int k, s;
int arr[15];
bool bit[2600002];
void getNum(int depth, int result) {
	if (depth == k) {
		if (result >= 0 && result <= 2600001)bit[result] = 1;
		return;
	}
	getNum(depth + 1, result + arr[depth]);
	getNum(depth + 1, result);
	getNum(depth + 1, result - arr[depth]);
}
void solve() {
	getNum(0, 0);
	int cnt = 0;
	for (int i = 1; i <= s; i++) {
		if (!bit[i])cnt++;
	}
	cout << cnt;
}
int main() {
	fast;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		s += arr[i];
	}
	solve();
	return 0;
}