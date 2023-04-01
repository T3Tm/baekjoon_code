#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/16236
	16236�� �Ʊ� ���
	�Ʊ� ���� ũ�Ⱑ 2�̴�.

	1. �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����.
	2. �ڽ��� ũ�⺸�� ���� ����⸦ �Դ´�.
	3. ũ�Ⱑ ������ ������ �������� ������ ���� �ִ�.



	1. ���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
	2. ����Ⱑ ������, ���� ����� ����⸦ ������ ����.
	2-1 ����� ����Ⱑ ������ ���� ���ʿ� �ִ� ����⸦ �Դ´�.
	(���� ���ʿ� �ִٴ� ���� column�� ���� ���� ��)

*/
using namespace std;
struct loc {
	int x, y, size, cnt, d;//��ŭ ����⸦ �Ծ����� Ȯ���ϱ�..
};
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int n, fishcnt;//����� ���� ����,��� ũ��
int arr[22][22];
loc shark;
loc sharkmove() {
	int visited[22][22];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = -1;
		}
	}
	loc tmp = { 22,22,shark.size,shark.cnt,shark.d };//���� �� �ִ� ���� ��ǥ
	long long dist = INT_MAX;
	queue<loc>Shark;
	Shark.push(shark);
	visited[shark.x][shark.y] = 0;//ó���� 0�̴�.
	while (!Shark.empty()) {
		auto [x, y, s, cnt, d] = Shark.front(); Shark.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visited[nx][ny] != -1)continue;
			if (arr[nx][ny] > s)continue;
			if (arr[nx][ny] && arr[nx][ny] < s) {//���� �� �ִ�.
				int ndist = visited[x][y] + 1;
				int ncnt = cnt + 1;
				int ns = s;
				if (ncnt == ns) {//�ڽ��� ũ�Ⱑ �ϳ� ���� �� �� �ִ�.
					ns++;
					ncnt = 0;
				}
				if (ndist < dist) {//�Ÿ��� ª�� �� ����.
					dist = visited[x][y] + 1;
					tmp = { nx,ny,ns,ncnt ,d + 1 };
				}
				else if (ndist == dist && tmp.x > nx) {//���� ��
					tmp = { nx,ny,ns ,ncnt,d + 1 };
				}
				else if (ndist == dist && tmp.x == nx && tmp.y > ny) {//���� ����
					tmp = { nx,ny,ns ,ncnt,d + 1 };
				}
				Shark.push({ nx,ny,ns ,ncnt,d + 1 });
			}
			else Shark.push({ nx,ny,s,cnt,d + 1 });//0�̰ų� ������
			visited[nx][ny] = visited[x][y] + 1;
		}
	}
	return tmp;
}
void solve() {
	while (fishcnt) {//����� ���� ���� ������.
		auto tmp = sharkmove();//�� �ּҷ� �����Ӱ� ���ÿ� ����.
		if (tmp.x == 22 && tmp.y == 22)break;//���� �� �ִ� �� ����.
		arr[tmp.x][tmp.y] = 0;//���� ���ֱ�.
		arr[shark.x][shark.y] = 0;//��� ��ġ ���ֱ�.
		shark = tmp;
		arr[shark.x][shark.y] = 9;//��� �ű��.
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
			if (arr[i][j] >= 1 && arr[i][j] <= 6)fishcnt++;//����� ���� ����.
			else if (arr[i][j] == 9)shark = { i,j,2,0 };//
		}
	}
	solve();
	return 0;
}