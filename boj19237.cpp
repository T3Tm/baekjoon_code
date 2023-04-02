#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19237
	19237번 어른 상어

	1의 번호를 가진 상어는 모두를 쫓아낸다.

	1. 모든 상어가 자신의 위치에 자신의 냄새를 뿌린다.
	2. 1초마다 모든 상어가 동시에 상하좌우 중 하나로 이동하고 자신의 냄새를 뿌림.
	(냄새는 k번 이동하면 사라짐 => 1초마다 움직이니까 k초 지나면 사라지는 거임)
	3. 이동 방향은 인접한 칸 중 아무 냄새가 없는 칸의 방향으로 잡는다.


	모든 상어가 이동한 후 한 칸에 여러 마리의 상어가 남아 있으면, 가장 작은 번호를 가진 상어를 제외하고 모두 격자 밖으로 쫓겨난다.
	해당 상어에


	*/
using namespace std;
struct SHARK {
	int x, y, s;//좌표와 방향을 가짐.
	int parr[4][4];//0,1,2,3 이동 방향에 우선순위 넣어놓기.
};
struct newArr {
	int num, smell;//해당 좌표에 몇 번의 냄새가 있는지
	int idx;//어떤 상어들이 있는지 확인.
};
int n, m, k;//n*n m개의 상어 k초 후에 냄새가 사라짐.
int outshark;
newArr arr[22][22];//배열
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<SHARK>shark;//상어들 좌표 갖고 있기.
bool isBoundary(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= n);
}
void spreadSmell(int depth) {//냄새 뿌리는 함수
	for (int i = 1; i <= m; i++) {
		auto& [x, y, s, parr] = shark[i];
		arr[x][y].num = i;//해당 숫자
		arr[x][y].smell = depth;//냄새가 언제 시작됐는지.
	}
}
void sharkMove() {//상어들 움직이면서, 겹치면 상어 쫓아내는 함수
	for (int i = 1; i <= m; i++) {
		auto& [x, y, s, parr] = shark[i];
		if (x == -1 && y == -1)continue;//해당 상어는 이미 쫓겨났음.
		int nx = -1, ny = -1, nexts = -1;
		bool flag = true;
		for (auto ns : parr[s]) {//s방향에서 우선순위인 가는 칸이 있음.
			nx = x + dx[ns];
			ny = y + dy[ns];
			nexts = ns;
			if (isBoundary(nx, ny))continue;//경계면 넘어감.
			if (arr[nx][ny].num == 0) {
				flag = false;
				break;//비어있으니 그냥 감
			}
		}
		if (flag) {//빈칸이 없음.
			for (auto ns : parr[s]) {//s방향에서 우선순위인 가는 칸이 있음.
				nx = x + dx[ns];
				ny = y + dy[ns];
				nexts = ns;
				if (isBoundary(nx, ny))continue;//경계면 넘어감.
				if (arr[nx][ny].num == i) break;//자신과 동일한 아이일 때 나감.
			}
		}
		arr[x][y].idx = 0;//전에 상어 위치 0으로 초기화
		if (arr[nx][ny].idx && arr[nx][ny].idx < i) {//해당하는 곳에 누가 있네?
			//Num이라는 애는 쫓겨나야함.
			outshark++;//상어 쫓겨남.
			x = -1;//좌표를 -1 ,-1로 주자. //parr필요없음.
			y = -1;
			continue;
		}
		arr[nx][ny].idx = i;//상어 위치 변환. 
		x = nx, y = ny, s = nexts;
	}
}
void removeSmell(int depth) {//각 칸 확인하면서 오래됐으면 냄새 삭제하자.
	for (int i = 0; i < n; i++) {//n*n칸에 냄새가 오래됐는지 확인.
		for (int j = 0; j < n; j++) {//누가 냄새를 남겼으면서 그 냄새가 k가 되는지 확인.
			if (arr[i][j].num && depth - arr[i][j].smell == k) {//냄새가 생긴지 k만큼 됐으면 없어져야됨.
				arr[i][j].num = 0;//냄새 지우고.
				arr[i][j].smell = 0;//냄새 또한 지우기.
			}
		}
	}
}
void solve() {
	int cntmove = 0;//몇 번 움직였는지.
	spreadSmell(cntmove);//상어들이 자신의 냄새를 뿌린다.
	while (m - 1 != outshark && cntmove <= 1000) {//1000초가 지나든지. 아니면 쫓겨난 상어가 m-1마리가 되든지
		sharkMove();//상어들이 움직인다.
		cntmove++;//한 번 움직임.
		spreadSmell(cntmove);
		if (cntmove >= k) {//냄새가 사라질 경우가 있음.
			removeSmell(cntmove);//냄새 사라지게 하기.
		}
	}
	cout << (cntmove == 1001 ? -1 : cntmove);
}
int main() {
	fast;
	cin >> n >> m >> k;
	shark.resize(m + 1, { -1,-1,-1 });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].num;//해당 숫자
			shark[arr[i][j].num] = { i,j };
		}
	}
	for (int i = 1; i <= m; i++) {//각 상어의 방향 입력 받기.
		cin >> shark[i].s;
		shark[i].s--;//방향은 초기에 1 줄여놓기.
		arr[shark[i].x][shark[i].y].idx = i;//i번호 상어가 들어있음.
	}
	for (int i = 1; i <= m; i++) {//각 상어의 우선순위 저장.
		for (int j = 0; j < 4; j++) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			shark[i].parr[j][0] = a - 1;
			shark[i].parr[j][1] = b - 1;
			shark[i].parr[j][2] = c - 1;
			shark[i].parr[j][3] = d - 1;
		}
	}
	solve();
	return 0;
}