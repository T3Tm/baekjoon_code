#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17142
	17142번 연구소 3
	마지막 연구소예유

	활성 상태와 비활성 상태가 있다.
	모든 바이러스는 비활성 상태

	m개를 활성 상태로 변경한다.

	n*n의 크기

	1. 백트래킹해서 활성화할 바이러스 찾는다.
	2. 활성한 바이러스를 기준으로 bfs를 돌린다.
	3. bfs를 돌린다음에 최소 시간을 갖고 온다. 끝

	복제가 1초가 걸림.

*/
using namespace std;
struct loc {
	int x, y;
};
int answer = INT_MAX;
int n, m, arr[52][52];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<loc>virus;//바이러스 좌표 받기
void bfs(vector<loc>& active_virus) {
	queue<loc>previrus;
	int visited[52][52]; memset(visited, -1, sizeof visited);
	for (auto v : active_virus) {
		previrus.push(v);
		visited[v.x][v.y] = 0;//현재 활성화된 바이러스는 0부터 시작
	}
	int temp = 0;
	while (!previrus.empty()) {
		auto [x, y] = previrus.front(); previrus.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (arr[nx][ny] == 1)continue;//1번이면 못 감.
			if (visited[nx][ny] == -1) {//가본 적 없기에
				visited[nx][ny] = visited[x][y] + 1;
				previrus.push({ nx,ny });
			}
			else if (visited[nx][ny] >= 0 && visited[nx][ny] > visited[x][y] + 1) {
				visited[nx][ny] = visited[x][y] + 1;
				previrus.push({ nx,ny });
			}
			if (arr[nx][ny] == 0) {//복제할 때만 시간초 재기
				temp = max(temp, visited[nx][ny]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && visited[i][j] == -1) {
				temp = -1;
				goto EXIT;
			}
		}
	}
EXIT:
	if (answer == INT_MAX)answer = temp;
	else if (answer == -1 && temp != -1) {
		answer = temp;
	}
	else if (answer != -1 && temp != -1) {
		answer = min(answer, temp);
	}
}
void backtrack(int depth, int pick[], int pre) {
	if (depth == m) {
		vector<loc>temp;//이것이 활성화할 아이들의 좌표들
		for (int i = 0; i < m; i++) {
			temp.push_back(virus[pick[i]]);
		}
		bfs(temp);
		return;
	}
	for (int i = pre + 1; i < virus.size(); i++) {
		pick[depth] = i;
		backtrack(depth + 1, pick, i);
		pick[depth] = 0;
	}
}
void solve() {
	int pick[2502]{ 0 };
	backtrack(0, pick, -1);
	cout << answer;
}
int main() {
	fast; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)virus.push_back({ i,j });
		}
	}
	solve();
	return 0;
}