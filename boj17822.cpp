#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17822
	17822�� ���� ������

	1. ��ȣ�� x�� ����� ������ d�������� kĭ ȸ����Ų��.
	d�� 0�̸� �ð� ���� deque���� right shift 1�̸� left shift �ϸ� �ȴ�.
	2. ���ǿ� ���� ���� ������, �����ϸ鼭 ���� ���� ���� ��� ã�´�.
	2-1. �����ϸ鼭 ���� �� �� �����.
	2-2. �����ϸ鼭 ���� ���� ������? ���ǿ� ���� ���� ����� ���Ѵ�. (��� �迭�� ���߰ڴ�)
	��պ��� ū ������ 1�� ����, ���� ������ 1�� ���Ѵ�. O(n)

	����� dx,dy�� �̿��ؼ� �� �Ʒ� ���� ������ �� ���鼭 ���� ���̸� ó���ϸ� �ȴ�.
*/
using namespace std;
int n, m, t;
vector<deque<int>>circle;
void circlerotate(int row, int dir, int k) {
	if (dir) {//�ݽð�� �����ߵ�.
		for (int i = 0; i < k; i++) {
			circle[row].push_back(circle[row].front());
			circle[row].pop_front();
		}
	}
	else {
		for (int i = 0; i < k; i++) {
			circle[row].push_front(circle[row].back());
			circle[row].pop_back();
		}
	}
}
void adjplus() {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	stack<pair<int, int>>tmp;
	long long total = 0;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (circle[i][j] != -1) {//-1�� ���� ����.
				total += circle[i][j];
				cnt++;
			}
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n)continue;
				if (ny >= m) {//���������� �Ѿ ��
					ny = 0;
				}
				if (ny < 0) {
					ny = m - 1;
				}
				if (circle[i][j] != -1 && circle[i][j] == circle[nx][ny]) {//
					tmp.push({ i,j });
					tmp.push({ nx,ny });
				}
			}
		}
	}
	if (tmp.empty()) {//���� �ְ� ����..?
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (circle[i][j] == -1)continue;
				if (circle[i][j] * cnt > total) {//��պ��� ũ��?
					circle[i][j]--;//��պ��� ũ�ϱ� 1 ����
				}
				else if (circle[i][j] * cnt < total) {//��պ��� �۾�.
					circle[i][j]++;//1����
				}
			}
		}
	}
	while (!tmp.empty()) {
		auto [x, y] = tmp.top(); tmp.pop();
		circle[x][y] = -1;//���� ó��
	}
}
long long Total() {
	long long temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (circle[i][j] != -1) {
				temp += circle[i][j];
			}
		}
	}
	return temp;
}
void solve() {
	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		for (int i = x; i <= n; i += x) {
			circlerotate(i - 1, d, k);
		}
		adjplus();
	}
	cout << Total();
}
int main() {
	fast;
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		deque<int>tmp(m);
		for (int j = 0; j < m; j++)cin >> tmp[j];
		circle.push_back(tmp);
	}
	solve();
	return 0;
}