#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/21610
   21610�� ������ ���� ��ٶ��

   0 1 2 3 4

   5 -> 1

*/
using namespace std;
map<int, pair<int, int>>MOVE = { {1,{0,-1}},{2,{-1,-1}},{3,{-1,0}},{4,{-1,1}},{5,{0,1}},{6,{1,1}},{7,{1,0}},{8,{1,-1}} };
int n, m;
int arr[52][52];
int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,-1,1 };
vector<pair<int, int>>cloud;//���� ��ǥ��
bool visited[52][52];
bool isBoundary(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}
void Boundary(int& x) {
	if (x >= n) {//�������� ���ƿ;���.
		x %= n;
	}
	else if (x < 0) {//���������� ���ƿ;���.
		int value = ((-x) % n);
		value = value ? value : n;
		x = n - value;//�������� 0�� ������ ��찡 ����.
	}
}
void cloudmove(int command, int jump) {
	auto next = MOVE[command];
	for (auto& loc : cloud) {//
		loc.first += (next.first * jump);
		loc.second += (next.second * jump);
		Boundary(loc.first);//���� �Ѿ�� �� Ȯ��
		Boundary(loc.second);
	}
}
void rain() {//���� ��ǥ�� �� ������ 1���� ��Ű��
	for (auto& loc : cloud) {
		arr[loc.first][loc.second]++;//�� ������
	}
}
void waterCopy() {//������ ���� ��ǥ���� ��������� ���� ���� -1,-1, -1,+1, +1,-1,+1,+1 4���� �������� ���������.
	stack<tuple<int, int, int>>query;
	for (auto& loc : cloud) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = loc.first + dx[i];
			int ny = loc.second + dy[i];
			if (isBoundary(nx, ny) && arr[nx][ny] >= 1) {
				cnt++;
			}
		}
		query.push({ loc.first,loc.second,cnt });//x,y ��ǥ�� cnt��� ���� ���ؾ���.
	}
	while (!query.empty()) {//�ش��ϴ� �� �����ؾߵǴ� �͵� �� �������ֱ�.
		auto temp = query.top();
		query.pop();
		arr[get<0>(temp)][get<1>(temp)] += get<2>(temp);
		visited[get<0>(temp)][get<1>(temp)] = 1;
	}
}
void newCloud() {//���ο� ���� ����.
	//visited �迭�� �����Ͽ� �ش��ϴ� ���� ������ �����ص� �Ǵ��� �Ǵ�.
	cloud.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] >= 2 && !visited[i][j]) {//�湮�ߴ� ���� �ƴϸ鼭 arr[i][j]���� 2���� ũ�� �ȴ�.
				arr[i][j] -= 2;
				cloud.push_back({ i,j });
			}
			visited[i][j] = 0;//��� ���� �湮 0ó��
		}
	}
}
long long WaterSum() {
	long long temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp += arr[i][j];
		}
	}
	return temp;
}
void solve() {
	while (m--) {//m���� Ŀ�ǵ尡 ����.
		int d, s;
		cin >> d >> s;
		cloudmove(d, s);//d�������� s��ŭ �����̱�
		rain();//�ش��ϴ� ���� �� ������
		waterCopy();//��������� ����Ű��
		newCloud();
	}
	cout << WaterSum();
}

int main() {
	fast;
	cin >> n >> m;
	cloud.push_back({ n - 1,0 });
	cloud.push_back({ n - 1,1 });
	cloud.push_back({ n - 2,0 });
	cloud.push_back({ n - 2,1 });
	//�ʱ� ���� �ֱ�.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}

