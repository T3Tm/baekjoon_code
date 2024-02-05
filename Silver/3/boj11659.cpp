#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11659
	11659번 구간 합 구하기 4
*/
using namespace std;
int n, m;
int prefix[100005];
int main() {
	fast;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> prefix[i];
		prefix[i] += prefix[i - 1];
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << prefix[b] - prefix[a - 1] << endl;
	}
	return 0;
}
