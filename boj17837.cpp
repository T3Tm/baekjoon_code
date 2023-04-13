#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17837
	17837�� ���ο� ���� 2

	n*n�� ü���ǿ��� ������ ����ȴ�. ���� ������ k��

	�ϳ��� �� ���� �ٸ� �� �ø� �� ����.
	ü������ �� ĭ�� ���, ������, �Ķ��� �� �ϳ���.

	���� ���� : ���� 4�� �̻� ���̴� ���� ������ ����ȴ�..

	A�� ���� �̵��Ϸ��� ĭ��
	1. ����̸� �� ĭ���� �̵� �̹� ĭ�� ���� ������ ���� ���� A�� ���� �ø�.

	2. �������� ��� �̵��� �Ŀ� A�� ���� �� ���� �ִ� ��� ���� �׿��ִ� ������ �ݴ�� �ٲ۴�.
	(���� �ִ� ������ �� �ٲ�.) ������ ���鸸 ���� �ݴ�.
	3. �Ķ����� ��쿡�� A�� ���� �̵� ������ �ݴ�� �ϰ� �� ĭ �̵��Ѵ�.
	������ �ݴ�� �ٲ� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��� �̵����� �ʰ� ������ ����.
	(�� �����̸� ������ �׷��� �ٲ�� ��.)

	0 : ���
	1 : ������
	2 : �Ķ���
*/
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
struct newArr {
	deque<int>nums;//���� ���� ������ �˾Ƴ���.
	int color;
};
struct info {
	int x, y, idxs, see;//deque�� �� ��°�� �ִ���. �������
};
newArr arr[14][14];
vector<info>horseinfo;//�� ������ deque�� �� ���� �ִ��� �˾Ƴ���.
int n, k;
int change[] = { 1,0,3,2 };
bool EXIT;
void horsemove() {
	for (auto& [x, y, idx, see] : horseinfo) {//
		int nx = x + dx[see];
		int ny = y + dy[see];//��������.
		if ((nx < 0 || nx >= n || ny < 0 || ny >= n) || arr[nx][ny].color == 2) {
			//�����̴ϱ� ��ǥ �Ѿ�ϱ� ������ �ٲٰ� ����
			see = change[see];//���� �ٲٰ�
			nx = x + dx[see];
			ny = y + dy[see];
			if (arr[nx][ny].color == 2 || (nx < 0 || nx >= n || ny < 0 || ny >= n)) {//�� ������.
				//�׳� ���ڸ��� �ֱ�.
				continue;
			}
		}
		int end = (int)arr[x][y].nums.size() - 1;
		deque<int>Td;
		for (; end >= idx; end--) {//�� ���� �� �Ű��ֱ�
			int tmpnum = arr[x][y].nums.back(); arr[x][y].nums.pop_back();
			Td.push_front(tmpnum);
		}
		if (arr[nx][ny].color == 1) {//������
			//�Ųٷ� �־��ָ��.
			int nextidx = arr[nx][ny].nums.size();
			while (!Td.empty()) {
				int tmpnum = Td.back(); Td.pop_back();//�ش� ���� �̴� ���ݾ�?
				arr[nx][ny].nums.push_back(tmpnum);
				horseinfo[tmpnum].idxs = nextidx++;
				horseinfo[tmpnum].x = nx;
				horseinfo[tmpnum].y = ny;
			}
		}
		else {//���
			//�׳� ��������.	
			int nextidx = arr[nx][ny].nums.size();
			while (!Td.empty()) {
				int tmpnum = Td.front(); Td.pop_front();
				arr[nx][ny].nums.push_back(tmpnum);//���� ����.
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
	while (turn <= 1000 && !EXIT) {//1000���� ũ�� �����ߵ�.
		horsemove();//�� �Ͽ� �����̸� ��.
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
		arr[x - 1][y - 1].nums.push_back(i);//���� �־����.
		horseinfo[i] = { x - 1,y - 1,0,z - 1 };//ó������ �� �ε��� 0���� ����.
	}
	solve();
	return 0;
}