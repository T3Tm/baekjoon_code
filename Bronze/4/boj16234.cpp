#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16234
	16234�� �α��̵�
*/
using namespace std;
int n, l, r;
int arr[52][52];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>>loc;
pair<int, int> dfs(int x, int y, bool visited[][52], int cnt, int total) {//�� �� ��������.
	visited[x][y] = true;
	loc.push_back({ x,y });//�ش� ��ǥ��
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;//�Ѿ
		if (visited[nx][ny])continue;//�̹� �湮�߾���
		if (abs(arr[nx][ny] - arr[x][y]) < l || abs(arr[nx][ny] - arr[x][y]) > r)continue;
		auto [tcnt, ttotal] = dfs(nx, ny, visited, cnt + 1, total + arr[nx][ny]);
		cnt = max(cnt, tcnt);
		total = max(total, ttotal);
	}
	return { cnt,total };
}
bool openboundary() {
	bool visited[52][52] = { false };
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				loc.clear();//����ְ�
				auto [cnt, total] = dfs(i, j, visited, 1, arr[i][j]);
				if (cnt >= 2)flag = true;
				while (!loc.empty()) {
					auto [x, y] = loc.back(); loc.pop_back();
					arr[x][y] = total / cnt;
				}
			}
		}
	}
	return flag;
}
void solve() {//
	int i;
	for (i = 0; openboundary(); i++);//���漱 ���鼭 �̵��ϱ�.
	cout << i;
}
int main() {
	fast;
	cin >> n >> l >> r;//n*n ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}