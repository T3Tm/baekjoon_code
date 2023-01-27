#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16174
	점프왕 쩰리 (Large)
	1. 출발점은 항상 정사각형 왼쪽 위다
	2. 이동 가능한 방향은 오른쪽과 아래이다.
	3. 가장 오른쪽 아래 칸에 도달하면 젤리가 우승
	4. 한 번에 밟고 있는 숫자만큼 오른쪽 또는 아래로 이동가능
*/
using namespace std;
int n;
vector<vector<int>>graph;
bool visited[66][66];
void jumpKing_jelly(int x,int y) {
	if (x == n - 1 && y == n - 1) {
		cout << "HaruHaru";
		exit(0);
	}
	visited[x][y]=true;
	int dist = graph[x][y];
	if (y + dist < n && !visited[x][y + dist])jumpKing_jelly(x, y + dist);
	if (x + dist < n && !visited[x + dist][y])jumpKing_jelly(x + dist, y);
}
int main() {
	fast;
	cin >> n;
	graph.resize(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	}
	jumpKing_jelly(0, 0);
	cout << "Hing";
	return 0;
}