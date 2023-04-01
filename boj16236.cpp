#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16236
	16236번 아기 상어
	아기 상어는 크기가 2이다.

	1. 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다.
	2. 자신의 크기보다 작은 물고기를 먹는다.
	3. 크기가 같으면 먹지는 못하지만 지나갈 수는 있다.



	1. 먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
	2. 물고기가 많으면, 가장 가까운 물고기를 먹으러 간다.
	2-1 가까운 물고기가 많으면 가장 왼쪽에 있는 물고기를 먹는다.
	(가장 왼쪽에 있다는 것은 column이 제일 작은 것)

*/
using namespace std;
struct loc {
	int x, y, size, cnt, d;//얼만큼 물고기를 먹었는지 확인하기..
};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, fishcnt;//물고기 갯수 세기,상어 크기
int arr[22][22];
loc shark;
loc sharkmove() {
	int visited[22][22];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = -1;
		}
	}
	loc tmp = { 22,22,shark.size,shark.cnt,shark.d };//먹을 수 있는 먹이 좌표
	long long dist = INT_MAX;
	queue<loc>Shark;
	Shark.push(shark);
	visited[shark.x][shark.y] = 0;//처음은 0이다.
	while (!Shark.empty()) {
		auto [x, y, s, cnt, d] = Shark.front(); Shark.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visited[nx][ny] != -1)continue;
			if (arr[nx][ny] > s)continue;
			if (arr[nx][ny] && arr[nx][ny] < s) {//먹을 수 있다.
				int ndist = visited[x][y] + 1;
				int ncnt = cnt + 1;
				int ns = s;
				if (ncnt == ns) {//자신의 크기가 하나 증가 될 수 있다.
					ns++;
					ncnt = 0;
				}
				if (ndist < dist) {//거리가 짧은 걸 먼저.
					dist = visited[x][y] + 1;
					tmp = { nx,ny,ns,ncnt ,d + 1 };
				}
				else if (ndist == dist && tmp.x > nx) {//가장 위
					tmp = { nx,ny,ns ,ncnt,d + 1 };
				}
				else if (ndist == dist && tmp.x == nx && tmp.y > ny) {//가장 왼쪽
					tmp = { nx,ny,ns ,ncnt,d + 1 };
				}
				Shark.push({ nx,ny,ns ,ncnt,d + 1 });
			}
			else Shark.push({ nx,ny,s,cnt,d + 1 });//0이거나 같으면
			visited[nx][ny] = visited[x][y] + 1;
		}
	}
	return tmp;
}
void solve() {
	while (fishcnt) {//물고기 갯수 없을 때까지.
		auto tmp = sharkmove();//상어가 최소로 움직임과 동시에 비우기.
		if (tmp.x == 22 && tmp.y == 22)break;//먹을 수 있는 게 없다.
		arr[tmp.x][tmp.y] = 0;//먹이 없애기.
		arr[shark.x][shark.y] = 0;//상어 위치 없애기.
		shark = tmp;
		arr[shark.x][shark.y] = 9;//상어 옮기기.
		fishcnt--;
	}
	cout << shark.d;
}
int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 6)fishcnt++;//물고기 갯수 세기.
			else if (arr[i][j] == 9)shark = { i,j,2,0 };//
		}
	}
	solve();
	return 0;
}