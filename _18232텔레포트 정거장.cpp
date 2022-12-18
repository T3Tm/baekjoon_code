#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/18232
	텔레포트 정거장
*/
using namespace std;
vector<vector<int>>graph(300000);
int visited[300001];
int n, m, s, e;
int teleport(int cur) {
	for (int i = 0; i < 300001; i++)visited[i] = -1;
	visited[cur] = 0;
	queue<int>loc;
	loc.push(cur);
	while (!loc.empty()) {
		int cur = loc.front(); loc.pop();
		if (cur == e)return visited[e];
		for (auto next : graph[cur]) {
			if (visited[next]==-1) {
				visited[next] = visited[cur] + 1;
				loc.push(next);
			}
		}
		for (int next : {cur + 1, cur - 1}) {
			if (next < 0 || next >= 300001)continue;
			if (visited[next] == -1) {
				visited[next] = visited[cur] + 1;
				loc.push(next);
			}
		}
	}
}
int main(){
	fast;
	cin >> n >> m >> s >> e;
	while (m--) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	cout << teleport(s);
	return 0;
}