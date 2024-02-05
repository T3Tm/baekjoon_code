#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/11660
	11660번 구간 합 구하기 5


*/
using namespace std;
long long prefix[1026][1026];
int n, m;
int main() {
	fast; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> prefix[i][j];
			prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
		}
	}
	while (m--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1] << endl;
	}
	return 0;
}