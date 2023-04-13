#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17837
	17837번 새로운 게임 2

	n*n판 체스판에서 게임이 진행된다. 말의 개수는 k개

	하나의 말 위에 다른 말 올릴 수 있음.
	체스판의 각 칸은 흰색, 빨간색, 파란색 중 하나임.

	종료 조건 : 말이 4개 이상 쌓이는 순간 게임이 종료된다..

	A번 말이 이동하려는 칸이
	1. 흰색이면 그 칸으로 이동 이미 칸에 말이 있으면 가장 위에 A번 말을 올림.

	2. 빨간색인 경우 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
	(원래 있던 말들은 안 바뀜.) 움직인 말들만 순서 반대.
	3. 파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
	방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우 이동하지 않고 가만히 있음.
	(못 움직이면 방향은 그래도 바꿔야 됨.)

	0 : 흰색
	1 : 빨간색
	2 : 파란색
*/
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
struct newArr {
	deque<int>nums;//무슨 값이 담겼는지 알아내기.
	int color;
};
struct info {
	int x, y, idxs, see;//deque의 몇 번째에 있는지. 방향까지
};
newArr arr[14][14];
vector<info>horseinfo;//말 정보들 deque의 몇 번에 있는지 알아내기.
int n, k;
int change[] = { 1,0,3,2 };
bool EXIT;
void horsemove() {
	for (auto& [x, y, idx, see] : horseinfo) {//
		int nx = x + dx[see];
		int ny = y + dy[see];//움직이자.
		if ((nx < 0 || nx >= n || ny < 0 || ny >= n) || arr[nx][ny].color == 2) {
			//움직이니까 좌표 넘어가니까 방향을 바꾸고 가자
			see = change[see];//방향 바꾸고
			nx = x + dx[see];
			ny = y + dy[see];
			if (arr[nx][ny].color == 2 || (nx < 0 || nx >= n || ny < 0 || ny >= n)) {//못 움직임.
				//그냥 제자리에 있기.
				continue;
			}
		}
		int end = (int)arr[x][y].nums.size() - 1;
		deque<int>Td;
		for (; end >= idx; end--) {//값 빼서 다 옮겨주기
			int tmpnum = arr[x][y].nums.back(); arr[x][y].nums.pop_back();
			Td.push_front(tmpnum);
		}
		if (arr[nx][ny].color == 1) {//빨간색
			//거꾸로 넣어주면됨.
			int nextidx = arr[nx][ny].nums.size();
			while (!Td.empty()) {
				int tmpnum = Td.back(); Td.pop_back();//해당 숫자 뽑는 거잖아?
				arr[nx][ny].nums.push_back(tmpnum);
				horseinfo[tmpnum].idxs = nextidx++;
				horseinfo[tmpnum].x = nx;
				horseinfo[tmpnum].y = ny;
			}
		}
		else {//흰색
			//그냥 움직이자.	
			int nextidx = arr[nx][ny].nums.size();
			while (!Td.empty()) {
				int tmpnum = Td.front(); Td.pop_front();
				arr[nx][ny].nums.push_back(tmpnum);//숫자 쌓자.
				horseinfo[tmpnum].idxs = nextidx++;
				horseinfo[tmpnum].x = nx;
				horseinfo[tmpnum].y = ny;
			}
		}
		if (arr[nx][ny].nums.size() >= 4) {
			EXIT = true;
		}
		x = nx, y = ny;
	}
}
void solve() {
	int turn = 0;
	while (turn <= 1000 && !EXIT) {//1000보다 크면 나가야됨.
		horsemove();//한 턴에 움직이면 됨.
		turn++;
	}
	cout << (turn == 1001 ? -1 : turn);
}
int main() {
	fast;
	cin >> n >> k;
	horseinfo.resize(k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].color;
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[x - 1][y - 1].nums.push_back(i);//숫자 넣어놓기.
		horseinfo[i] = { x - 1,y - 1,0,z - 1 };//처음에는 다 인덱스 0번에 있음.
	}
	solve();
	return 0;
}