#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17086
	17086번 아기 상어 2

*/
using namespace std;
struct loc {
	int x, y, d;
};
int n, m, answer;
int arr[52][52];
int dx[] = { 0,-1,-1,-1,0,1,1,1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int babyshark(int x, int y) {
	bool visited[52][52] = { false };
	queue<loc>shark;
	shark.push({ x,y,0 });
	visited[x][y] = true;
	while (!shark.empty()) {
		auto [x, y, d] = shark.front(); shark.pop();
		if (arr[x][y])return d;
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (visited[nx][ny])continue;
			visited[nx][ny] = true;
			shark.push({ nx,ny,d + 1 });//
		}
	}
}
int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!arr[i][j]) {
				answer = max(answer, babyshark(i, j));
			}
		}
	}
	cout << answer;
	return 0;
}