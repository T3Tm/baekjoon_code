#include <bits/stdc++.h>//
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/17182
	17182번 우주 탐사선

	행 마다 다른 행으로 가는 최소 구하는 데 걸리는 시간
	nlogn을 모든 n행에 대해서 하는 시간
	n^nlogn
	100*logn의 시간으로 해결 가능

*/
using namespace std;
struct loc {
	int c, x;
	bool operator () (loc& a, loc& b) {
		return a.c > b.c;
	}
};
int n, k;
int arr[12][12];
int dist[12][12];//거리 저장.
int answer = 100000;//최대
int result[12];
bool visited[12];
void Dijkstra(int start) {//하나의 행에서 다른 행까지 거리 구하기.
	priority_queue<loc, vector<loc>, loc>Loc;
	Loc.push({ 0,start });//어디 행?
	dist[start][start] = 0;//
	while (!Loc.empty()) {
		auto pre = Loc.top(); Loc.pop();
		for (int i = 0; i < n; i++) {
			if (pre.c + arr[pre.x][i] < dist[start][i]) {//해당하는 행으로 가는데 걸리는 게 최소가 바뀔 수 있음.
				dist[start][i] = pre.c + arr[pre.x][i];
				Loc.push({ dist[start][i],i });//해당 행으로 갔음.
			}
		}
	}
}
void comb(int depth) {
	if (depth == n) {
		int temp = 0;
		int pre = result[0];
		for (int i = 1; i < n; i++) {
			int next = result[i];
			temp += dist[pre][next];
			pre = next;
		}
		answer = min(answer, temp);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			result[depth] = i;
			comb(depth + 1);
			visited[i] = false;
		}
	}
}
int main() {
	fast;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dist[i][j] = 1002;//최대
		}
	}
	for (int i = 0; i < n; i++) {
		Dijkstra(i);
	}
	result[0] = k;
	visited[k] = true;
	comb(1);
	cout << answer;
	return 0;
}