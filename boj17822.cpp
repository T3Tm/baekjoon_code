#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17822
	17822번 원판 돌리기

	1. 번호가 x의 배수인 원판을 d방향으로 k칸 회전시킨다.
	d가 0이면 시계 방향 deque에서 right shift 1이면 left shift 하면 된다.
	2. 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다.
	2-1. 인접하면서 같은 수 다 지우기.
	2-2. 인접하면서 같은 수가 없으면? 원판에 적힌 수의 평균을 구한다. (모든 배열을 봐야겠다)
	평균보다 큰 수에서 1을 빼고, 작은 수에는 1을 더한다. O(n)

	결론은 dx,dy를 이용해서 위 아래 왼쪽 오른쪽 을 보면서 같은 수이면 처리하면 된다.
*/
using namespace std;
int n, m, t;
vector<deque<int>>circle;
void circlerotate(int row, int dir, int k) {
	if (dir) {//반시계로 돌려야됨.
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
			if (circle[i][j] != -1) {//-1일 수도 있음.
				total += circle[i][j];
				cnt++;
			}
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n)continue;
				if (ny >= m) {//오른쪽으로 넘어간 거
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
	if (tmp.empty()) {//같은 애가 없네..?
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (circle[i][j] == -1)continue;
				if (circle[i][j] * cnt > total) {//평균보다 크네?
					circle[i][j]--;//평균보다 크니까 1 감소
				}
				else if (circle[i][j] * cnt < total) {//평균보다 작아.
					circle[i][j]++;//1증가
				}
			}
		}
	}
	while (!tmp.empty()) {
		auto [x, y] = tmp.top(); tmp.pop();
		circle[x][y] = -1;//없앰 처리
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