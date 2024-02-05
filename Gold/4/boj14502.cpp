#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14502
	14502번 연구소

	n*m  직사각형 크기

	바이러스가 상하좌우 퍼져감.

	세울 수 이는 벽의 갯수는 3개

	벽을 세워서 => 안전 영역의 크기를 구해라.

	벽의 위치를 combination으로 뽑아서 각 board에다가 넣고

	dfs 돌리면 될 것 같다.


*/
using namespace std;
struct loc {
	int x, y;
};
int board[12][12], n, m;
int pre[12][12];
long long answer;
vector<loc>zero;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void virus(loc cur, bool visited[][12]) {//bfs 구현하기 귀찮다.. 그냥dfs 할랭
	visited[cur.x][cur.y] = 1;
	board[cur.x][cur.y] = 2;//바이러스 공간 만들어 줬던 거 다시 다 풀어줘야 되는데.. 귀찮다..
	for (int i = 0; i < 4; i++) {
		int nx = cur.x + dx[i];
		int ny = cur.y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;//경계면 넘어감
		if (visited[nx][ny] || board[nx][ny])continue;//갈 수 없음
		virus({ nx,ny }, visited);
	}
}
void arrcpy(int src[][12], int dst[][12]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
void maxSafe(bool visited[][12]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j] == 2) {//바이러스 퍼지게 하자.
				virus({ i,j }, visited);
			}
		}
	}
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!board[i][j])cnt++;
		}
	}
	answer = max(answer, cnt);
}
void solve() {//for문 3개로 zero 뽑아냈음. 그럼 그 위치에다가 board 칠하기
	for (int i = 0; i + 2 < zero.size(); i++) {
		for (int j = i + 1; j + 1 < zero.size(); j++) {
			for (int z = j + 1; z < zero.size(); z++) {
				auto [f1, f2] = zero[i];
				auto [s1, s2] = zero[j];
				auto [t1, t2] = zero[z];
				board[f1][f2] = board[s1][s2] = board[t1][t2] = 1;//가상 벽 만들기
				bool visited[12][12]{ 0 };
				maxSafe(visited);
				arrcpy(pre, board);
			}
		}
	}
	cout << answer;
}
int main() {
	fast; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			pre[i][j] = board[i][j];
			if (!board[i][j])zero.push_back({ i,j });
		}
	}
	solve();
	return 0;
}