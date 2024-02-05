#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/15653
	15653번 구슬 탈출 4
	
	구슬 탈출 3에서 많이 관점을 변경했다.
	bfs 돌리다가 새로운 좌표 받고 넘겨줬다.
*/
using namespace std;
int n, m;
struct loc {
	int x, y;
	bool operator ==(const loc& t) {
		return x == t.x && y == t.y;
	}
};
long long answer = -1;
vector<vector<char>>board;
loc red, blue;//빨강 파랑 구슬 좌표 갖고 있기.
vector<loc>MOVE{ {-1,0},{0,1},{1,0},{0,-1} };
vector<char>change{ 'U','R','D','L' };
loc target;
pair<loc, loc> beadmove(loc&R,loc&B,int dir) {//
	loc nR = R, nB = B;
	//.이다 = '.';//.이다
	if (dir == 0) {//위
		if (R.x < B.x) {//R이 먼저 움직이고 B가 움직인다.
			while (nR.x - 1 >= 0 && !(loc{nR.x - 1, nR.y}==B) && board[nR.x - 1][nR.y] != '#' && board[nR.x - 1][nR.y] != 'O')nR.x--;
			if (board[nR.x - 1][nR.y] == 'O') {
				nR.x--;//그 지점 보내주기.
			}
			while (nB.x - 1 >= 0 && !(loc{ nB.x - 1, nB.y } == nR) && board[nB.x - 1][nB.y] != '#' && board[nB.x - 1][nB.y] != 'O')nB.x--;
			if (board[nB.x - 1][nB.y] == 'O') {
				nB.x--;//그 지점 보내주기.
			}
		}
		else {//B를 먼저 움직여 줘야함.
			while (nB.x - 1 >= 0 && !(loc{ nB.x - 1, nB.y } == R) && board[nB.x - 1][nB.y] != '#' && board[nB.x - 1][nB.y] != 'O')nB.x--;
			if (board[nB.x - 1][nB.y] == 'O') {
				nB.x--;//그 지점 보내주기.
			}
			while (nR.x - 1 >= 0 && !(loc{ nR.x - 1, nR.y } == nB) && board[nR.x - 1][nR.y] != '#' && board[nR.x - 1][nR.y] != 'O')nR.x--;
			if (board[nR.x - 1][nR.y] == 'O') {
				nR.x--;//그 지점 보내주기.
			}
		}
	}
	else if (dir == 1) {//오른쪽
		if (R.y > B.y) {//R이 먼저 움직이고 B가 움직인다.
			while (nR.y + 1 < m && !(loc{ nR.x , nR.y+1 } == B) && board[nR.x][nR.y + 1] != '#' && board[nR.x][nR.y + 1] != 'O')nR.y++;
			if (board[nR.x][nR.y + 1] == 'O') {
				nR.y++;//그 지점 보내주기.
			}
			while (nB.y + 1 < m && !(loc{ nB.x, nB.y+1 } == nR) && board[nB.x][nB.y + 1] != '#' && board[nB.x][nB.y + 1] != 'O')nB.y++;
			if (board[nB.x][nB.y + 1] == 'O') {
				nB.y++;//그 지점 보내주기.
			}
		}
		else {
			while (nB.y + 1 < m && !(loc{ nB.x , nB.y+1 } == R) && board[nB.x][nB.y + 1] != '#' && board[nB.x][nB.y + 1] != 'O')nB.y++;
			if (board[nB.x][nB.y + 1] == 'O') {
				nB.y++;//그 지점 보내주기.
			}
			while (nR.y + 1 < m && !(loc{ nR.x, nR.y+1 } == nB) && board[nR.x][nR.y + 1] != '#' && board[nR.x][nR.y + 1] != 'O')nR.y++;
			if (board[nR.x][nR.y + 1] == 'O') {
				nR.y++;//그 지점 보내주기.
			}
		}
	}
	else if (dir == 2) {//아래
		if (R.x > B.x) {//R이 먼저 움직이고 B가 움직인다.
			while (nR.x + 1 < n && !(loc{ nR.x+1, nR.y } == B) && board[nR.x + 1][nR.y] != '#' && board[nR.x + 1][nR.y] != 'O')nR.x++;
			if (board[nR.x + 1][nR.y] == 'O') {
				nR.x++;//그 지점 보내주기.
			}
			while (nB.x + 1 < n && !(loc{ nB.x+1, nB.y  } == nR) && board[nB.x + 1][nB.y] != '#' && board[nB.x + 1][nB.y] != 'O')nB.x++;
			if (board[nB.x + 1][nB.y] == 'O') {
				nB.x++;//그 지점 보내주기.
			}
		}
		else {
			while (nB.x + 1 < n && !(loc{ nB.x+1, nB.y } == R) && board[nB.x + 1][nB.y] != '#' && board[nB.x + 1][nB.y] != 'O')nB.x++;
			if (board[nB.x + 1][nB.y] == 'O') {
				nB.x++;//그 지점 보내주기.
			}
			while (nR.x + 1 < n && !(loc{ nR.x+1, nR.y  } == nB) && board[nR.x + 1][nR.y] != '#' && board[nR.x + 1][nR.y] != 'O')nR.x++;
			if (board[nR.x + 1][nR.y] == 'O') {
				nR.x++;//그 지점 보내주기.
			}
		}
	}
	else {//왼쪽
		if (R.y < B.y) {//R이 먼저 움직이고 B가 움직인다.
			while (nR.y - 1 >= 0 && !(loc{ nR.x, nR.y - 1 } == B) && board[nR.x][nR.y - 1] != '#' && board[nR.x][nR.y - 1] != 'O')nR.y--;
			if (board[nR.x][nR.y - 1] == 'O') {
				nR.y--;//그 지점 보내주기.
			}
			while (nB.y - 1 >= 0 && !(loc{ nB.x, nB.y - 1 } == nR) && board[nB.x][nB.y - 1] != '#' && board[nB.x][nB.y - 1] != 'O')nB.y--;
			if (board[nB.x][nB.y - 1] == 'O') {
				nB.y--;//그 지점 보내주기.
			}
		}
		else {
			while (nB.y - 1 >= 0 && !(loc{ nB.x, nB.y - 1 } == R) && board[nB.x][nB.y - 1] != '#' && board[nB.x][nB.y - 1] != 'O')nB.y--;
			if (board[nB.x][nB.y - 1] == 'O') {
				nB.y--;//그 지점 보내주기.
			}
			while (nR.y - 1 >= 0 && !(loc{ nR.x, nR.y - 1 } == nB) && board[nR.x][nR.y - 1] != '#' && board[nR.x][nR.y - 1] != 'O')nR.y--;
			if (board[nR.x][nR.y - 1] == 'O') {
				nR.y--;//그 지점 보내주기.
			}
		}
	}
	return { nR,nB };
}
void bead() {//최근 빨간색 좌표와 파랑색의 좌표.
	bool visited[12][12][12][12];
	memset(visited, false, sizeof visited);//다 -1로 초기화
	queue<tuple<loc,loc,int>>Rq;//빨강 파랑 갖고 있는데 해당하는 것을 누가 더 큰지 대결.
	Rq.push({ red,blue ,0});
	visited[red.x][red.y][blue.x][blue.y]=true;
	while (!Rq.empty()) {
		auto [cr, cb,dist] = Rq.front(); Rq.pop();//각각 레드 블루 좌표
		if (cb == target)continue;
		else if (cr == target) {
			answer = dist; return;
		}
		for (int i = 0;i< 4; i++) {//방향 정하기.
			auto [ncr,ncb] = beadmove(cr,cb,i);//움직이기.
			if (visited[ncr.x][ncr.y][ncb.x][ncb.y])continue;//이미 방문했던 적 있었으면 안 가.
			Rq.push({ ncr,ncb,dist + 1 });
			visited[ncr.x][ncr.y][ncb.x][ncb.y] = true;
		}
	}
}
void solve() {
	board[red.x][red.y] = board[blue.x][blue.y] = '.';
	bead();
	cout << answer << endl;
}
int main() {
	fast; cin >> n >> m;
	board.resize(n, vector<char>(m));
	for (int i = 0; i < n; i++) {
		string tmp; cin >> tmp;
		for (int j = 0; j < m; j++) {
			board[i][j] = tmp[j];
			if (board[i][j] == 'O')target = { i,j };
			else if (board[i][j] == 'R')red = { i,j };
			else if (board[i][j] == 'B')blue = { i,j };
		}
	}
	solve();
	return 0;
}