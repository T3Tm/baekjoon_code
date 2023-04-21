#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/15644
	15644번 구슬 탈출 3

	n*m 크기의 판이 있다.
	
	보드에는 구멍이 하나가 있다.
	빨간 구슬을 구멍을 통해 빼낸다.
	이때 파란 구슬이 구멍에 들어가면 안된다.
	
	왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래로 기울이기.
	
	1. 공은 동시에 움직인다.
	2. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다.
	3. 빨간 ,파란 동시에 빠져도 안된다.
	4. 기울이기 동작은 구슬이 더이상 안 움직일 때까지 진행한다.
	
	최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지, 또 어떻게 기울여야 하는지 구하는 프로그램을
	작성하시오.

	시간 제한은 2초이다.
	해당하는 구슬이 움직일 수 있는 경로는 총 4개이다.
	
	10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.

	그럼 아이가 0,0,0,0,0,0,0,0,0,0 이 열 동작에서 각각 4개씩 고를 수 있다.
	최대 경우의 수는 4^10 이다. 즉 2^20이다.
	이 경우의 수는 1048576이기 때문에 그 경우의 수 안에 빨간 구슬이 나가면 그 경우의 수에서
	최소 depth 를 알아낸다. 
	
	만약 빨간 구슬이 나갔는데 파란 구슬도 나가면 바로 return 해서 돌아간다.

	1. 빨간 구슬 , 파란 구슬 둘 다의 좌표를 갖고 백트래킹한다.
	

	방향에 맞혀서 누가더 가까이 있었는지 판단하면 된다.
	예를 들어) 위였으면 x좌표가 더 작은 아이가 더 위에 있었던 거니까 그 아이가 먼저 배열에서 움직이고 그다음에 다른 애가 움직인다.
	
	L 3
	R 1
	U 0
	D 2
	0,1,2,3,4,5,6,7,8,9,10
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
vector<char>result(12);//
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
void bead(int depth,loc curRed,loc curBlue, vector<char>&base) {//최근 빨간색 좌표와 파랑색의 좌표.
	if (curRed == target || curBlue == target || depth==10) {
		if (curRed == target && !(curBlue == curRed)) {//결국은 도착했음.
			if (depth < answer) {
				answer = depth;//더 짧게 갈 수 있었음.
				result = base;
			}
			else if (answer == -1) {//첨에는 그냥 들어갈 수 있게끔
				answer = depth;
				result = base;
			}
		}
		return;
	}
	vector<vector<char>>cache(n,vector<char>(m));
	arrcpy(board,cache);//현재 상태 저장.
	for (int i = 0; i < 4; i++) {//위, 현재 상황 에서 골라서 가기.
		//현재 board에서 red와 blue를 옮겨서 다음으로 넘어가자.
		auto [nR,nB] = movebead(curRed,curBlue,i);//빨강 움직이고 파랑 움직이자.
		base[depth] = change[i];
		bead(depth + 1,nR, nB,base);//새로운 빨강과 파랑의 좌표.
		arrcpy(cache, board);
		base[depth] = '\0';//빈칸으로 바꾸기
	}
}
void solve() {
	vector<char>base(12);
	bead(0,red,blue,base);
	cout << answer << endl;
	for (int i = 0; i < answer; i++) {
		cout << result[i];
	}
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

