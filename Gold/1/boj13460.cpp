#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/13460
	13460번 구슬 탈출 2

*/
using namespace std;
int n, m;
struct loc {
	int x, y;
	bool operator ==(const loc& t) {
		return x == t.x && y == t.y;
	}
};
long long answer=-1;
vector<vector<char>>board;
loc red, blue;//빨강 파랑 구슬 좌표 갖고 있기.
vector<loc>MOVE{ {-1,0},{0,1},{1,0},{0,-1} };
vector<char>change{ 'U','R','D','L' };
loc target;
void arrcpy(vector<vector<char>>& src, vector<vector<char>>& dst) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dst[i][j] = src[i][j];
		}
	}
}
pair<loc,loc> movebead(loc& R, loc& B,int dir) {
	char tmp[13][13];
	loc nR=R, nB=B;
	//움직이기 전에 자신의 위치를 일단 0으로 바꾸고 움직이자~
	if (dir == 0) {//위
		if (R.x < B.x) {//R이 먼저 움직이고 B가 움직인다.
			board[R.x][R.y] =  '.';//.이다
			while (nR.x-1>=0 && board[nB.x - 1][nB.y] != 'B' && board[nR.x-1][nR.y]!='#'&& board[nR.x-1][nR.y]!='O')nR.x--;
			if (board[nR.x - 1][nR.y] == 'O') {
				nR.x--;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
			board[B.x][B.y] = '.';//.이다
			while (nB.x - 1 >= 0 && board[nB.x - 1][nB.y] != 'R' && board[nB.x - 1][nB.y] != '#' && board[nB.x - 1][nB.y] != 'O')nB.x--;
			if (board[nB.x - 1][nB.y] == 'O') {
				nB.x--;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
		}
		else {//B를 먼저 움직여 줘야함.
			board[B.x][B.y] = '.';//.이다
			while (nB.x - 1 >= 0 && board[nB.x - 1][nB.y] != 'R' && board[nB.x - 1][nB.y] != '#' && board[nB.x - 1][nB.y] != 'O')nB.x--;
			if (board[nB.x - 1][nB.y] == 'O') {
				nB.x--;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
			board[R.x][R.y] = '.';//.이다
			while (nR.x - 1 >= 0 && board[nR.x - 1][nR.y] != 'B' && board[nR.x - 1][nR.y] != '#' && board[nR.x - 1][nR.y] != 'O')nR.x--;
			if (board[nR.x - 1][nR.y] == 'O') {
				nR.x--;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
		}
	}
	else if (dir == 1) {//오른쪽
		if (R.y > B.y) {//R이 먼저 움직이고 B가 움직인다.
			board[R.x][R.y] = '.';//.이다
			while (nR.y + 1 < m && board[nR.x + 1][nR.y] != 'B' && board[nR.x][nR.y + 1] != '#' && board[nR.x][nR.y + 1] != 'O')nR.y++;
			if (board[nR.x][nR.y + 1] == 'O') {
				nR.y++;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
			board[B.x][B.y] = '.';//.이다
			while (nB.y + 1 < m && board[nB.x][nB.y + 1] != 'R' && board[nB.x][nB.y + 1] != '#' && board[nB.x][nB.y + 1] != 'O')nB.y++;
			if (board[nB.x][nB.y + 1] == 'O') {
				nB.y++;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
		}
		else {
			board[B.x][B.y] = '.';//.이다
			while (nB.y + 1 < m && board[nB.x][nB.y + 1] != 'R' && board[nB.x][nB.y+1] != '#' && board[nB.x][nB.y+1] != 'O')nB.y++;
			if (board[nB.x][nB.y+1] == 'O') {
				nB.y++;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
			board[R.x][R.y] = '.';//.이다
			while (nR.y + 1 < m && board[nR.x][nR.y+1] != 'B' && board[nR.x][nR.y+1] != '#' && board[nR.x][nR.y+1] != 'O')nR.y++;
			if (board[nR.x][nR.y+1] == 'O') {
				nR.y++;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
		}
	}
	else if (dir == 2) {//아래
		if (R.x > B.x) {//R이 먼저 움직이고 B가 움직인다.
			board[R.x][R.y] = '.';//.이다
			while (nR.x +1 <n && board[nR.x+1][nR.y] != 'B' && board[nR.x + 1][nR.y] != '#' && board[nR.x + 1][nR.y] != 'O')nR.x++;
			if (board[nR.x + 1][nR.y] == 'O') {
				nR.x++;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
			board[B.x][B.y] = '.';//.이다
			while (nB.x +1 < n && board[nB.x + 1][nB.y] != 'R' && board[nB.x + 1][nB.y] != '#' && board[nB.x + 1][nB.y] != 'O')nB.x++;
			if (board[nB.x + 1][nB.y] == 'O') {
				nB.x++;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
		}
		else {
			board[B.x][B.y] = '.';//.이다
			while (nB.x +1 < n && board[nB.x + 1][nB.y] != 'R' && board[nB.x + 1][nB.y] != '#' && board[nB.x + 1][nB.y] != 'O')nB.x++;
			if (board[nB.x + 1][nB.y] == 'O') {
				nB.x++;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
			board[R.x][R.y] = '.';//.이다
			while (nR.x +1 < n && board[nR.x + 1][nR.y] != 'B' && board[nR.x + 1][nR.y] != '#' && board[nR.x + 1][nR.y] != 'O')nR.x++;
			if (board[nR.x + 1][nR.y] == 'O') {
				nR.x++;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
		}
	}
	else {//왼쪽
		if (R.y < B.y) {//R이 먼저 움직이고 B가 움직인다.
			board[R.x][R.y] = '.';//.이다
			while (nR.y -1>=0 && board[nR.x][nR.y-1] != 'B' && board[nR.x][nR.y -1] != '#' && board[nR.x][nR.y - 1] != 'O')nR.y--;
			if (board[nR.x][nR.y - 1] == 'O') {
				nR.y--;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] = 'R';
			}
			board[B.x][B.y] = '.';//.이다
			while (nB.y-1 >=0 && board[nB.x][nB.y - 1] != 'R' && board[nB.x][nB.y - 1] != '#' && board[nB.x][nB.y - 1] != 'O')nB.y--;
			if (board[nB.x][nB.y - 1] == 'O') {
				nB.y--;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
		}
		else {
			board[B.x][B.y] = '.';//.이다
			while (nB.y -1>=0 && board[nB.x][nB.y - 1] != 'R' && board[nB.x][nB.y - 1] != '#' && board[nB.x][nB.y - 1] != 'O')nB.y--;
			if (board[nB.x][nB.y - 1] == 'O') {
				nB.y--;//그 지점 보내주기.
			}
			else if (board[nB.x][nB.y] == '.') {
				board[nB.x][nB.y] = 'B';
			}
			board[R.x][R.y] = '.';//.이다
			while (nR.y -1>=0 && board[nR.x][nR.y -1] != 'B' && board[nR.x][nR.y -1] != '#' && board[nR.x][nR.y - 1] != 'O')nR.y--;
			if (board[nR.x][nR.y- 1] == 'O') {
				nR.y--;//그 지점 보내주기.
			}
			else if (board[nR.x][nR.y] == '.') {
				board[nR.x][nR.y] ='R';
			}
		}
	}
	return { nR,nB };
}
void bead(int depth,loc curRed,loc curBlue) {//최근 빨간색 좌표와 파랑색의 좌표.
	if (curRed == target || curBlue == target || depth==10) {
		if (curRed == target && !(curBlue == curRed)) {//결국은 도착했음.
			if (depth < answer) {
				answer = depth;//더 짧게 갈 수 있었음.
			}
			else if (answer == -1) {//첨에는 그냥 들어갈 수 있게끔
				answer = depth;
			}
		}
		return;
	}
	vector<vector<char>>cache(n,vector<char>(m));
	arrcpy(board,cache);//현재 상태 저장.
	for (int i = 0; i < 4; i++) {//위, 현재 상황 에서 골라서 가기.
		//현재 board에서 red와 blue를 옮겨서 다음으로 넘어가자.
		auto [nR,nB] = movebead(curRed,curBlue,i);//빨강 움직이고 파랑 움직이자.
		bead(depth + 1,nR, nB);//새로운 빨강과 파랑의 좌표.
		arrcpy(cache, board);
	}
}
void solve() {
	bead(0,red,blue);
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

