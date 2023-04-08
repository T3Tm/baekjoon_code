#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/19238
	19238�� ��ŸƮ �ý�
	���� �°��� ���� ž���ϴ� ���� ����.
	�̵� �� ���� ������ �ִܰ�η� ����. < bfs�̿��ϸ� �ȴ�.
	1. �մ��� �������� ������ �ٶ����� ���ᰡ ������.
	(���ᰡ �ٴڳ��� �� ���� ������ ����.)
	2. M���� �°��� �¿� ����
	�°����� �ýø� Ÿ�� �����δ�.


	1. �ִ� �Ÿ��� �̵��Ѵ�. (�ýö� �°��̶� ���� ���� ���� ����)
	(�� ��ȣ�� ���� ���� �°� < �� ��ȣ�� ���� ���� �°�)
	2. �°��� �������� �̵���Ű�� ����, �̵��ϸ鼭 �Ҹ��� ���ᰡ 2��� �����ȴ�.
	3. �̵��ϴٰ� ���ᰡ �ٴڳ��� ������ ����.(�������� �����ߴµ� ���ᰡ 0�̸� ���а� �ƴ�)


	2������ �迭���� �մ����� �Ǻ��ϸ� �ȴ�.
	���������� ���� �մ� ��ȣ�� ���� .,
*/
using namespace std;
int n, m;
struct Taxi {
	int x, y;
	long long e;//������
};
struct my {
	int x, y, num;
};
Taxi taxi;
vector<vector<pair<int, vector<bool>>>>cst;//���� ���� �°� ���� �� �ִ�.
int arr[22][22];
long long answer;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
my find() {
	int visited[22][22] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = -1;
		}
	}
	queue<Taxi>loc;
	loc.push(taxi);
	visited[taxi.x][taxi.y] = 0;//ù ��ġ 0
	int mindist = INT_MAX;//�ּҷ� �� �� �ִ� �Ÿ� �˾Ƴ���.
	my number = { -1,-1 ,-1 };//�ּ� �Ÿ��� ��� �˾Ƴ���.
	while (!loc.empty()) {
		auto [x, y, e] = loc.front(); loc.pop();
		if (cst[x][y].first != 0) {//�°��� ���� ��
			if (visited[x][y] < mindist) {
				mindist = visited[x][y];
				number = { x,y,cst[x][y].first };
			}
			else if (visited[x][y] == mindist) {
				if (number.x > x) {//���� �� �۱⿡ �ٲ�ߵ�.
					number = { x,y,cst[x][y].first };
				}
				else if (number.x == x && number.y > y) {
					number = { x,y,cst[x][y].first };//���� �� �۾Ƽ� �ٲ�ߵ�.
				}
			}
		}
		if (e == 0)continue;//���̻� �� �����δ�~
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visited[nx][ny] != -1)continue;//�湮������ �Ѿ��.
			if (arr[nx][ny] == 1)continue;//�� ��
			visited[nx][ny] = visited[x][y] + 1;
			loc.push({ nx,ny,e - 1 });//��ĭ �������ٿ�
		}
	}
	if (mindist == INT_MAX) {
		answer = -1;
		return number;
	}
	else {
		cst[number.x][number.y].first = 0;//�ش� �� 0���� �ʱ�ȭ.
		taxi = { number.x,number.y,taxi.e - visited[number.x][number.y] };
		return number;
	}
}
long long takedest(int dest) {//�ش� ������ ���� ���ߵ�.
	bool visited[22][22] = { false };
	queue<Taxi>loc;
	loc.push(taxi);
	while (!loc.empty()) {
		auto [x, y, e] = loc.front(); loc.pop();
		if (cst[x][y].second[dest]) {
			long long tmp = taxi.e;
			cst[x][y].second[dest] = 0;//0���� �ʱ�ȭ.
			taxi = { x,y,e };
			return tmp - e;//�󸶳� �������� ������.?
		}
		if (e == 0)continue;//���̻� �� ������.
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;
			if (visited[nx][ny])continue;//�湮������ �Ѿ��.
			if (arr[nx][ny] == 1)continue;//�� ��
			visited[nx][ny] = visited[x][y] + 1;
			loc.push({ nx,ny,e - 1 });//��ĭ �������ٿ�
		}
	}
	answer = -1;
	return -1;
}
void energy(long long dist) {
	taxi.e += dist * 2;//�Ÿ��� 2�踸ŭ ä���ش�.
}
void solve() {
	while (m--) {
		auto num = find();//�ִܰŸ��� ��� �°����� �� ������ �˾Ƴ���.
		if (num.num == -1)break;//���ʿ� �� ���ٴ� ��.
		long long dist = takedest(num.num);//�������� �������ֱ�. �׸��� �Ÿ� �ޱ�.
		if (dist == -1)break;
		energy(dist);//������ ����
	}
	cout << (answer == -1 ? -1 : taxi.e);
}

int main() {
	fast;
	cin >> n >> m >> taxi.e;//
	cst.resize(n, vector<pair<int, vector<bool>>>(n, { 0,vector<bool>(m + 1,0) }));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> taxi.x >> taxi.y;
	taxi.x--;
	taxi.y--;
	for (int i = 0; i < m; i++) {
		int r, c, dr, dc;
		cin >> r >> c >> dr >> dc;//
		cst[r - 1][c - 1].first = i + 1;//first�� ���������� 
		cst[dr - 1][dc - 1].second[i + 1] = 1;//���� ������.
	}
	solve();
	return 0;
}