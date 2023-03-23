#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/4485
	4485�� ��� �� ���� �ְ� ������?

	�ּҷ� �Ҿ�� �Ѵ�.

*/
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n;
struct Loc {
	int c, x, y;
};
struct cmp {
	bool operator()(Loc& a, Loc& b) {
		return a.c > b.c;
	}
};
int zelda(int arr[127][127]) {
	int visited[127][127] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = INT_MAX;
		}
	}
	visited[0][0] = 0;
	priority_queue<Loc, vector<Loc>, cmp>loc;
	loc.push({ 0,0,0 });//cost, x,y��ǥ
	while (!loc.empty()) {
		auto value = loc.top(); loc.pop();
		for (int i = 0; i < 4; i++) {
			int nx = value.x + dx[i];
			int ny = value.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (value.c + arr[nx][ny] < visited[nx][ny]) {
				visited[nx][ny] = value.c + arr[nx][ny];
				loc.push({ visited[nx][ny],nx,ny });
			}
		}
	}
	return visited[n - 1][n - 1] + arr[0][0];
}
int main() {//�ش��ϴ� �ּҿ� 
	fast;
	for (int idx = 1;; idx++) {
		cin >> n;
		if (n == 0)break;
		int arr[127][127] = { 0 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		cout << "Problem " << idx << ": " << zelda(arr) << endl;
	}
	return 0;
}