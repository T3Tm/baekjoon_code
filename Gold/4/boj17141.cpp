#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17141
	17141번 연구소 2
	N×N크기임
	연구소에 바이러스 M개를 놓을 것이다.

	빈 칸에 바이러스를 놓는다. 상하좌우로 바이러스가 복제가 된다. 복제하는데 1초가 걸린다.

	바이러스가 퍼지는 데 걸리는 최솟값
	흠.. 전에 있던 거랑 뭐가 다른 거지?.. 모르겠는데..
*/
using namespace std;
struct loc {
	int x, y;
};
int n, m, board[52][52];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<loc>virus;
int answer = INT_MAX;
void bfs(vector<loc>& dvirus) {
	queue<loc>virus_loc;//이러면 되지요~
	int visited[52][52]; memset(visited, -1, sizeof visited);//-1로 초기화 하고.
	//초기 virus랑 addvirus의 공간에는 0으로 넣어줘야 되는데..
	for (auto v : dvirus) {//현재 뽑은 바이러스
		virus_loc.push(v);
		visited[v.x][v.y] = 0;//초기에는 0으로 초기화 해줘야됨.
	}
	int temp = 0;
	while (!virus_loc.empty()) {
		auto [x, y] = virus_loc.front(); virus_loc.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;;//경계면 체크
			if (board[nx][ny] != 0)continue;//빈칸만 복제할 수 있음.
			if (visited[nx][ny] >= 0 && visited[nx][ny] > visited[x][y] + 1) {//이미 들어간 적 있을 때는 퍼지고 있는 터라 값이 줄어들 수도 있음.
				visited[nx][ny] = visited[x][y] + 1;//전에 값에서 1더해서 더 작을 수 있음.
				virus_loc.push({ nx,ny });
			}
			else if (visited[nx][ny] == -1) {//아직 한 번도 안 감.
				visited[nx][ny] = visited[x][y] + 1;//전에 것에서 1 더한다.
				virus_loc.push({ nx,ny });
			}
			temp = max(temp, visited[nx][ny]);//temp에는 bfs로 퍼지는 시간의 최댓값을 갖고 와야됨
		}
	}
	//중요한 것은 지금 빈칸인데 board[i][j]==0인데 visited가 -1인 값이 있으면 temp는 -1이 되는 거임
	for (int i = 0; i < n; i++) {//흠 모든 결과 값을 정리하고 -1하는것도 좋은듯
		for (int j = 0; j < n; j++) {
			if (!board[i][j] && visited[i][j] == -1) {
				temp = -1;
				goto EXIT;
			}
		}
	}
EXIT:
	if (answer == INT_MAX)answer = temp;
	else if (answer == -1 && temp != -1) {//지금 만약 INT_MAX가 아닌 상황에서
		answer = temp;//통과하는 경우가 있음.
	}
	else if (answer != -1 && temp != -1) {//원래 값이 있었고, temp에도 값이 있으니까 더 작은 거 저장
		answer = min(answer, temp);
	}
}
void backtrack(int depth, int pick[], int pre) {//흠... 흠냐 흠냐
	if (depth == m) {//m개를 뽑았습니더.
		vector<loc>temp;
		for (int i = 0; i < m; i++) {
			auto [x, y] = virus[pick[i]];
			board[x][y] = 2;//바이러스 놓기
			temp.push_back(virus[pick[i]]);
		}
		//뽑은 곳에 바이러스 다 놓았으니 이제 bfs 돌려서 최소 시간 갖고 오면됨.
		bfs(temp);//그 다음 다시 원복 상태로 만들기 바이러스 값 갖고 와야되네..
		while (!temp.empty()) {
			auto [x, y] = temp.back(); temp.pop_back();
			board[x][y] = 0;//0으로 놓기.
		}
		return;
	}
	//백트래킹으로 넣어줘야되는 것은
	for (int i = pre + 1; i < virus.size(); i++) {//바이러스칸 만큼 여기도 최적화를 돌릴까..
		pick[depth] = i;//해당 depth에는 i번째를 뽑음
		backtrack(depth + 1, pick, i);
		pick[depth] = 0;
	}
}
void solve() {//백트래킹으로 뽑읍시당.
	int pick[2502]{ 0 };
	backtrack(0, pick, -1);//여기서 그럼 나올 것이고.
	cout << answer;
}
int main() {
	fast; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				virus.push_back({ i,j });
				board[i][j] = 0;
			}
		}
	}
	solve();
	return 0;
}