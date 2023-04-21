#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17780
	17780번 새로운 게임

	2와는 다르게 제일 아래 있는 것만 움직일 수 있다.
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
		if (idx != 0)continue;
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