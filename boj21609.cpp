#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21609
	21609�� ��� ���б�

	������ �͵��� ���� ������ ��� �湮 �迭���� �ʱ�ȭ ���ֱ�.

	���� ū �� �׷��� ã�´�
	1. �� �׷��� dfs�� ã�´�
	2. ������ �� �� �����Ѵ�.
	3. ���� �� �����Ѵ�.
*/
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
int arr[22][22];
vector<pair<int, int>>Zero;//��.. 0�� ��ǥ�� �Ź� �޶����� ����
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
		visited[x][y] = false;//�ʱ�ȭ�ϱ�.
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
		if (arr[nx][ny] == 0 || arr[nx][ny] == num) {//nx ,ny�� 0�̰ų�, num
			if (arr[nx][ny] == 0)cnt++;
			dfs(nx, ny, visited, num, cnt);
		}
	}
}
void findblock() {
	bool visited[22][22] = { false };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && arr[i][j] >= 1) {//�Ϲ� ���� 1�̻� �׸��� �湮 �� �߾����.
				int tmpcnt = 0;//������ ���� ������.
				tmpstand = { 99,99 };//���� �׷��� ���� ��
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
			tmparr[i][j] = -2;//�� -2�� �ʱ�ȭ
		}
	}
	for (int column = 0; column < n; column++) {
		int idx = n - 1;
		for (int row = n - 1; row >= 0; row--) {
			if (arr[row][column] >= 0) {//���ڸ� �׳� ������ �ȴ�.
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
	int tmparr[22][22];//�迭 ������.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmparr[i][j] = -2;//�� -2�� �ʱ�ȭ
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