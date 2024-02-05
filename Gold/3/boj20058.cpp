#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
	https://www.acmicpc.net/problem/20058
	20058�� ������ ���� ���̾��

	0,0 0,1    0,2 0,3
	1,0 1,1    1,2 1,3
	(x+plus-1)-i = 0
			   1,2
			   1,3

	A[r][c]�� 0�̸� ������ ���� ��.
	������ �ִ� ĭ 3�� �Ǵ� 4���� ���������� ���� ĭ�� ������ ���� 1 �پ��.
*/
using namespace std;
int n, q, r;
int arr[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
inline int Intpow(int src, int repeat) {
	int temp = 1;
	for (int i = 0; i < repeat; i++)temp *= src;
	return temp;
}
void rotate(int x, int y, int plus) {//�ش� ���� �迭 90�� ������
	int temp[100][100] = { 0 };
	for (int i = x + plus - 1; i >= x; i--) {//1
		for (int j = y; j < y + plus; j++) {//1
			temp[x + (j - y)][y + ((x + plus - 1) - i)] = arr[i][j];
		}
	}

	for (int i = x; i < x + plus; i++) {//1
		for (int j = y; j < y + plus; j++) {//1
			arr[i][j] = temp[i][j];
		}
	}
}
void splitAndRotate(int l) {
	int plus = Intpow(2, l);
	for (int i = 0; i < r; i += plus) {//64
		for (int j = 0; j < r; j += plus) {//64
			rotate(i, j, plus);
		}
	}
}
void melt() {//�ϳ��� �������� ������ ���� Ž������ �� 3�� �̻��� ������ ������ �ϳ��� ������ ���� 1 �پ���.
	stack<pair<int, int>>temp;
	for (int i = 0; i < r; i++) {//64
		for (int j = 0; j < r; j++) {//64
			int cnt = 0;
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= r || ny < 0 || ny >= r) continue;
				if (arr[nx][ny] > 0)cnt++;
			}
			if (cnt < 3) {
				temp.push({ i,j });
			}
		}
	}
	while (!temp.empty()) {//��ǥ�� ���.
		auto loc = temp.top(); temp.pop();
		arr[loc.first][loc.second] = (arr[loc.first][loc.second] - 1) < 0 ? 0 : arr[loc.first][loc.second] - 1;//1 �پ��
	}
}
long long ice() {
	long long sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			sum += arr[i][j];
		}
	}
	return sum;
}
bool visited[100][100];
int dfs(int x, int y, int cnt) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= r)continue;
		if (visited[nx][ny] || !arr[nx][ny])continue;
		cnt = max(cnt, dfs(nx, ny, cnt + 1));
	}
	return cnt;
}
int iceberg() {
	int result = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			if (!visited[i][j] && arr[i][j])result = max(result, dfs(i, j, 1));
		}
	}
	return result;
}
void solve() {//
	while (q--) {//1000
		int cmd;
		cin >> cmd;//�ش��ϴ� Ŀ�ǵ�
		if (cmd != 0)splitAndRotate(cmd);//���� ������ ������.
		melt();//���
	}
	//8192
	cout << ice() << endl << iceberg();
}
int main() {
	fast;
	cin >> n >> q;
	r = Intpow(2, n);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}

