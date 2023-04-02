#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19237
	19237�� � ���

	1�� ��ȣ�� ���� ���� ��θ� �ѾƳ���.

	1. ��� �� �ڽ��� ��ġ�� �ڽ��� ������ �Ѹ���.
	2. 1�ʸ��� ��� �� ���ÿ� �����¿� �� �ϳ��� �̵��ϰ� �ڽ��� ������ �Ѹ�.
	(������ k�� �̵��ϸ� ����� => 1�ʸ��� �����̴ϱ� k�� ������ ������� ����)
	3. �̵� ������ ������ ĭ �� �ƹ� ������ ���� ĭ�� �������� ��´�.


	��� �� �̵��� �� �� ĭ�� ���� ������ �� ���� ������, ���� ���� ��ȣ�� ���� �� �����ϰ� ��� ���� ������ �Ѱܳ���.
	�ش� ��


	*/
using namespace std;
struct SHARK {
	int x, y, s;//��ǥ�� ������ ����.
	int parr[4][4];//0,1,2,3 �̵� ���⿡ �켱���� �־����.
};
struct newArr {
	int num, smell;//�ش� ��ǥ�� �� ���� ������ �ִ���
	int idx;//� ������ �ִ��� Ȯ��.
};
int n, m, k;//n*n m���� ��� k�� �Ŀ� ������ �����.
int outshark;
newArr arr[22][22];//�迭
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
vector<SHARK>shark;//���� ��ǥ ���� �ֱ�.
bool isBoundary(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= n);
}
void spreadSmell(int depth) {//���� �Ѹ��� �Լ�
	for (int i = 1; i <= m; i++) {
		auto& [x, y, s, parr] = shark[i];
		arr[x][y].num = i;//�ش� ����
		arr[x][y].smell = depth;//������ ���� ���۵ƴ���.
	}
}
void sharkMove() {//���� �����̸鼭, ��ġ�� ��� �ѾƳ��� �Լ�
	for (int i = 1; i <= m; i++) {
		auto& [x, y, s, parr] = shark[i];
		if (x == -1 && y == -1)continue;//�ش� ���� �̹� �Ѱܳ���.
		int nx = -1, ny = -1, nexts = -1;
		bool flag = true;
		for (auto ns : parr[s]) {//s���⿡�� �켱������ ���� ĭ�� ����.
			nx = x + dx[ns];
			ny = y + dy[ns];
			nexts = ns;
			if (isBoundary(nx, ny))continue;//���� �Ѿ.
			if (arr[nx][ny].num == 0) {
				flag = false;
				break;//��������� �׳� ��
			}
		}
		if (flag) {//��ĭ�� ����.
			for (auto ns : parr[s]) {//s���⿡�� �켱������ ���� ĭ�� ����.
				nx = x + dx[ns];
				ny = y + dy[ns];
				nexts = ns;
				if (isBoundary(nx, ny))continue;//���� �Ѿ.
				if (arr[nx][ny].num == i) break;//�ڽŰ� ������ ������ �� ����.
			}
		}
		arr[x][y].idx = 0;//���� ��� ��ġ 0���� �ʱ�ȭ
		if (arr[nx][ny].idx && arr[nx][ny].idx < i) {//�ش��ϴ� ���� ���� �ֳ�?
			//Num�̶�� �ִ� �Ѱܳ�����.
			outshark++;//��� �Ѱܳ�.
			x = -1;//��ǥ�� -1 ,-1�� ����. //parr�ʿ����.
			y = -1;
			continue;
		}
		arr[nx][ny].idx = i;//��� ��ġ ��ȯ. 
		x = nx, y = ny, s = nexts;
	}
}
void removeSmell(int depth) {//�� ĭ Ȯ���ϸ鼭 ���������� ���� ��������.
	for (int i = 0; i < n; i++) {//n*nĭ�� ������ �����ƴ��� Ȯ��.
		for (int j = 0; j < n; j++) {//���� ������ �������鼭 �� ������ k�� �Ǵ��� Ȯ��.
			if (arr[i][j].num && depth - arr[i][j].smell == k) {//������ ������ k��ŭ ������ �������ߵ�.
				arr[i][j].num = 0;//���� �����.
				arr[i][j].smell = 0;//���� ���� �����.
			}
		}
	}
}
void solve() {
	int cntmove = 0;//�� �� ����������.
	spreadSmell(cntmove);//������ �ڽ��� ������ �Ѹ���.
	while (m - 1 != outshark && cntmove <= 1000) {//1000�ʰ� ��������. �ƴϸ� �Ѱܳ� �� m-1������ �ǵ���
		sharkMove();//������ �����δ�.
		cntmove++;//�� �� ������.
		spreadSmell(cntmove);
		if (cntmove >= k) {//������ ����� ��찡 ����.
			removeSmell(cntmove);//���� ������� �ϱ�.
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
			cin >> arr[i][j].num;//�ش� ����
			shark[arr[i][j].num] = { i,j };
		}
	}
	for (int i = 1; i <= m; i++) {//�� ����� ���� �Է� �ޱ�.
		cin >> shark[i].s;
		shark[i].s--;//������ �ʱ⿡ 1 �ٿ�����.
		arr[shark[i].x][shark[i].y].idx = i;//i��ȣ �� �������.
	}
	for (int i = 1; i <= m; i++) {//�� ����� �켱���� ����.
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