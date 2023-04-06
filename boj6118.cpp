#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cout.tie(nullptr),cin.tie(nullptr)
/*
	https://www.acmicpc.net/problem/6118
	6118번 숨바꼭질

	m개의 양방향 길로 이어져 있다.

*/
using namespace std;
int n, m;
vector<vector<int>>graph;
vector<int>idxs;
int visited[20002];
void init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = -1;
	}
}
void bfs(int x) {
	visited[x] = 0;
	queue<int>data;
	data.push(x);
	while (!data.empty()) {
		int cur = data.front(); data.pop();
		for (auto next : graph[cur]) {
			if (visited[next] >= 0)continue;
			visited[next] = visited[cur] + 1;
			if (!idxs.empty()) {
				if (visited[idxs[0]] < visited[next]) {
					idxs.clear();
					idxs.push_back(next);
				}
				else if (visited[idxs[0]] == visited[next]) {
					idxs.push_back(next);
				}
			}
			else {
				idxs.push_back(next);
			}
			data.push(next);
		}
	}
}
void solve() {
	init();
	bfs(1);
	sort(idxs.begin(), idxs.end());
	cout << idxs[0] << ' ' << visited[idxs[0]] << ' ' << idxs.size();
}
int main() {
	fast;
	cin >> n >> m;
	graph.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
		graph[a].push_back(b);
	}
	solve();
	return 0;
}