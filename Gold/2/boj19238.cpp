#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19238
	19238번 스타트 택시
	여러 승객이 같이 탑승하는 경우는 없다.
	이동 할 때는 무조건 최단경로로 간다. < bfs이용하면 된다.
	1. 손님을 도착지로 데려다 줄때마다 연료가 충전됨.
	(연료가 바닥나면 그 날의 업무가 끝남.)
	2. M명의 승객을 태울 거임
	승객들은 택시를 타고 움직인다.


	1. 최단 거리로 이동한다. (택시랑 승객이랑 같이 있을 수도 있음)
	(행 번호가 가장 작은 승객 < 열 번호가 가장 작은 승객)
	2. 승객을 목적지로 이동시키고 나면, 이동하면서 소모한 연료가 2배로 충전된다.
	3. 이동하다가 연료가 바닥나면 업무가 끝남.(목적지에 도달했는데 연료가 0이면 실패가 아님)


	2번부터 배열에서 손님으로 판별하면 된다.
	도착지점도 같이 손님 번호로 하자 .,
*/
using namespace std;
int n, m;
struct Taxi {
	int x, y;
	long long e;//에너지
};
struct my {
	int x, y, num;
};
Taxi taxi;
vector<vector<pair<int, vector<bool>>>>cst;//여러 명의 승객 있을 수 있다.
int arr[22][22];
long long answer;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
my find() {
	int visited[22][22] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = -1;
		}
	}
	queue<Taxi>loc;
	loc.push(taxi);
	visited[taxi.x][taxi.y] = 0;//첫 위치 0
	int mindist = INT_MAX;//최소로 갈 수 있는 거리 알아내기.
	my number = { -1,-1 ,-1 };//최소 거리의 사람 알아내기.
	while (!loc.empty()) {
		auto [x, y, e] = loc.front(); loc.pop();
		if (cst[x][y].first != 0) {//승객이 있을 때
			if (visited[x][y] < mindist) {
				mindist = visited[x][y];
				number = { x,y,cst[x][y].first };
			}
			else if (visited[x][y] == mindist) {
				if (number.x > x) {//행이 더 작기에 바꿔야됨.
					number = { x,y,cst[x][y].first };
				}
				else if (number.x == x && number.y > y) {
					number = { x,y,cst[x][y].first };//열이 더 작아서 바꿔야됨.
				}
			}
		}
		if (e == 0)continue;//더이상 못 움직인다~
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visited[nx][ny] != -1)continue;//방문했으면 넘어가기.
			if (arr[nx][ny] == 1)continue;//못 감
			visited[nx][ny] = visited[x][y] + 1;
			loc.push({ nx,ny,e - 1 });//한칸 움직였다요
		}
	}
	if (mindist == INT_MAX) {
		answer = -1;
		return number;
	}
	else {
		cst[number.x][number.y].first = 0;//해당 곳 0으로 초기화.
		taxi = { number.x,number.y,taxi.e - visited[number.x][number.y] };
		return number;
	}
}
long long takedest(int dest) {//해당 목적지 까지 가야됨.
	bool visited[22][22] = { false };
	queue<Taxi>loc;
	loc.push(taxi);
	while (!loc.empty()) {
		auto [x, y, e] = loc.front(); loc.pop();
		if (cst[x][y].second[dest]) {
			long long tmp = taxi.e;
			cst[x][y].second[dest] = 0;//0으로 초기화.
			taxi = { x,y,e };
			return tmp - e;//얼마나 에너지를 썻는지.?
		}
		if (e == 0)continue;//더이상 못 움직임.
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visited[nx][ny])continue;//방문했으면 넘어가기.
			if (arr[nx][ny] == 1)continue;//못 감
			visited[nx][ny] = visited[x][y] + 1;
			loc.push({ nx,ny,e - 1 });//한칸 움직였다요
		}
	}
	answer = -1;
	return -1;
}
void energy(long long dist) {
	taxi.e += dist * 2;//거리의 2배만큼 채워준다.
}
void solve() {
	while (m--) {
		auto num = find();//최단거리로 어느 승객한테 갈 것인지 알아낸다.
		if (num.num == -1)break;//애초에 못 간다는 거.
		long long dist = takedest(num.num);//목적지로 데려다주기. 그리고 거리 받기.
		if (dist == -1)break;
		energy(dist);//에너지 충전
	}
	cout << (answer == -1 ? -1 : taxi.e);
}

int main() {
	fast;
	cin >> n >> m >> taxi.e;//
	cst.resize(n, vector<pair<int, vector<bool>>>(n, { 0,vector<bool>(m + 1,0) }));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> taxi.x >> taxi.y;
	taxi.x--;
	taxi.y--;
	for (int i = 0; i < m; i++) {
		int r, c, dr, dc;
		cin >> r >> c >> dr >> dc;//
		cst[r - 1][c - 1].first = i + 1;//first는 시작지점들 
		cst[dr - 1][dc - 1].second[i + 1] = 1;//도착 지점들.
	}
	solve();
	return 0;
}