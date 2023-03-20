#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/21610
   21610번 마법사 상어와 비바라기

   0 1 2 3 4

   5 -> 1

*/
using namespace std;
map<int, pair<int, int>>MOVE = { {1,{0,-1}},{2,{-1,-1}},{3,{-1,0}},{4,{-1,1}},{5,{0,1}},{6,{1,1}},{7,{1,0}},{8,{1,-1}} };
int n, m;
int arr[52][52];
int dx[] = { -1,-1,1,1 };
int dy[] = { -1,1,-1,1 };
vector<pair<int, int>>cloud;//구름 좌표들
bool visited[52][52];
bool isBoundary(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}
void Boundary(int& x) {
	if (x >= n) {//왼쪽으로 돌아와야함.
		x %= n;
	}
	else if (x < 0) {//오른쪽으로 돌아와야함.
		int value = ((-x) % n);
		value = value ? value : n;
		x = n - value;//나머지가 0이 나오는 경우가 생김.
	}
}
void cloudmove(int command, int jump) {
	auto next = MOVE[command];
	for (auto& loc : cloud) {//
		loc.first += (next.first * jump);
		loc.second += (next.second * jump);
		Boundary(loc.first);//경계면 넘어가는 거 확인
		Boundary(loc.second);
	}
}
void rain() {//구름 좌표에 물 내려서 1증가 시키기
	for (auto& loc : cloud) {
		arr[loc.first][loc.second]++;//비 내리기
	}
}
void waterCopy() {//이전의 구름 좌표에서 물복사버그 마법 시전 -1,-1, -1,+1, +1,-1,+1,+1 4개의 방향으로 물어봐야함.
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
		query.push({ loc.first,loc.second,cnt });//x,y 좌표에 cnt라는 값을 더해야함.
	}
	while (!query.empty()) {//해당하는 물 증가해야되는 것들 다 증가해주기.
		auto temp = query.top();
		query.pop();
		arr[get<0>(temp)][get<1>(temp)] += get<2>(temp);
		visited[get<0>(temp)][get<1>(temp)] = 1;
	}
}
void newCloud() {//새로운 구름 얻어내기.
	//visited 배열을 참고하여 해당하는 곳에 구름이 생성해도 되는지 판단.
	cloud.clear();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] >= 2 && !visited[i][j]) {//방문했던 것이 아니면서 arr[i][j]값이 2보다 크면 된다.
				arr[i][j] -= 2;
				cloud.push_back({ i,j });
			}
			visited[i][j] = 0;//모든 공간 방문 0처리
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
	while (m--) {//m번의 커맨드가 있음.
		int d, s;
		cin >> d >> s;
		cloudmove(d, s);//d방향으로 s만큼 움직이기
		rain();//해당하는 곳에 비 내리기
		waterCopy();//물복사버그 일으키기
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
	//초기 구름 넣기.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	solve();
	return 0;
}

