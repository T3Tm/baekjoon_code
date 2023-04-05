#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21609
	21609번 상어 중학교

	제로인 것들은 따로 빼놔서 계속 방문 배열에서 초기화 해주기.

	가장 큰 블럭 그룹을 찾는다
	1. 블럭 그룹을 dfs로 찾는다
	2. 무지개 블럭 수 저장한다.
	3. 기준 블럭 저장한다.
*/
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int arr[22][22];
vector<pair<int, int>>Zero;//아.. 0의 좌표가 매번 달라지는 구나
pair<int, int>tmpstand;
vector<pair<int, int>>standblock;
vector<pair<int, int>>tmpblock;
int rainbowcnt;
pair<int, int>stand;
long long answer;
inline long long intpow(int t) {
	return t * t;
}
void Zeroreset(bool visited[][22]) {
	for (auto [x, y] : Zero) {
		visited[x][y] = false;//초기화하기.
	}
}
void dfs(int x, int y, bool visited[][22], int num, int& cnt) {
	if (arr[x][y] == num) {
		if (x < tmpstand.first) {
			tmpstand = { x,y };
		}
		else if (x == tmpstand.first) {
			if (y < tmpstand.second) {
				tmpstand = { x,y };
			}
		}
	}
	if (!arr[x][y]) {
		Zero.push_back({ x,y });
	}
	visited[x][y] = true;
	tmpblock.push_back({ x,y });
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
		if (visited[nx][ny])continue;
		if (arr[nx][ny] == 0 || arr[nx][ny] == num) {//nx ,ny가 0이거나, num
			if (arr[nx][ny] == 0)cnt++;
			dfs(nx, ny, visited, num, cnt);
		}
	}
}
void findblock() {
	bool visited[22][22] = { false };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] >= 1) {//일반 블럭은 1이상 그리고 방문 안 했어야함.
				int tmpcnt = 0;//무지개 갯수 세보기.
				tmpstand = { 99,99 };//현재 그룹의 기준 블럭
				tmpblock.clear();
				dfs(i, j, visited, arr[i][j], tmpcnt);
				if (standblock.size() < tmpblock.size()) {
					standblock = tmpblock;
					stand = tmpstand;
					rainbowcnt = tmpcnt;
				}
				else if (standblock.size() == tmpblock.size()) {
					if (rainbowcnt < tmpcnt) {
						standblock = tmpblock;
						stand = tmpstand;
						rainbowcnt = tmpcnt;
					}
					else if (rainbowcnt == tmpcnt) {
						if (stand.first < tmpstand.first) {
							standblock = tmpblock;
							stand = tmpstand;
							rainbowcnt = tmpcnt;
						}
						else if (stand.first == tmpstand.first) {
							if (stand.second < tmpstand.second) {
								standblock = tmpblock;
								stand = tmpstand;
								rainbowcnt = tmpcnt;
							}
						}
					}
				}
				Zeroreset(visited);
				Zero.clear();//
			}
		}
	}
}
void deleteblock() {
	answer += intpow(standblock.size());
	while (!standblock.empty()) {
		auto [x, y] = standblock.back(); standblock.pop_back();
		arr[x][y] = -2;
	}
}
void gravity() {
	int tmparr[22][22] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmparr[i][j] = -2;//다 -2로 초기화
		}
	}
	for (int column = 0; column < n; column++) {
		int idx = n - 1;
		for (int row = n - 1; row >= 0; row--) {
			if (arr[row][column] >= 0) {//숫자면 그냥 내려도 된다.
				tmparr[idx--][column] = arr[row][column];
			}
			if (arr[row][column] == -1) {
				idx = row;
				tmparr[idx--][column] = arr[row][column];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = tmparr[i][j];
		}
	}
}
void leftrotate() {
	int tmparr[22][22];//배열 돌리기.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmparr[i][j] = -2;//다 -2로 초기화
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmparr[(n - 1) - j][i] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = tmparr[i][j];
		}
	}
}
void solve() {
	while (1) {
		findblock();
		if (standblock.size() >= 2) {
			deleteblock();
		}
		else {
			break;
		}
		gravity();
		leftrotate();
		gravity();
	}
	cout << answer;
}
int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}