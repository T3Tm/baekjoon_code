#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/18429
  18429번 근손실
*/
using namespace std;
using ll = long long;
int n, k;
ll answer;
int arr[10];
bool avail[10];
void Muscle_synthesis(int depth, ll result) {
	if (result < 500)return;//애초에 못 만드는 아이.
	if (depth == n) {
		if (result >= 500)answer++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!avail[i]) {
			avail[i] = 1;
			Muscle_synthesis(depth + 1, result + arr[i] - k);
			avail[i] = 0;
		}
	}
}
void solve() {
	Muscle_synthesis(0, 500);
	cout << answer;
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> arr[i];
	solve();
	return 0;
}