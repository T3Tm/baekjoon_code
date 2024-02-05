#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16174
	16174번 점프왕 쩰리 (Large)
	
	경계면 벗어나면 게임 패배
	
	0,0에서 시작
	0,1 or 1,0 으로만 움직임
	N-1,N-1 에 도착하면 게임 끝
*/
using namespace std;
int n,arr[66][66];
int main() {
	fast; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	bool v[66][66]{};
	queue<pair<int, int>>q;
	q.push({ 0,0 });
	while (!q.empty()) {
		auto[x,y]=q.front(); q.pop();
		if (x == n - 1 && y == n - 1) {
			cout << "HaruHaru"; exit(0);
		}
		for (auto [dx, dy] : { pair{0,arr[x][y]},pair{arr[x][y],0} }) {
			int nx = x + dx, ny = y + dy;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (v[nx][ny])continue;
			v[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	cout << "Hing";
	return 0;
}