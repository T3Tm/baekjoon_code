#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14284
	간선 이어가기 2
	정점 n개 0개의 간선으로 이루어진 무방향 그래프 주어짐.

	m개의 가중치 간선의 정보가 있는 간선 리스트가 주어짐.
	
	간선리스트에 있는 간선 하나씩 그래프에 추가할 건데,

	특정 정점 s와 t가 연결되는 시점에서 간선 추가를 멈출 거임 < ㅇㅋ

	연결이란 두 정점이 간선을 ㅌ통해 방문 가능한 것을 말한다.

	s와 t가 연결 되는 시점의 간선의 가중치의 합이 최소가 되게 추가하는 간선의 순서를
	조정할 때 
	그 최솟값을 구해라~

	s와 t가 연결되는 시점의 간선의 가중치 합의 최솟값?
	a,b,c 가중치가 양수입니다.
	간선들을 받아들인다.
	입력 m
	sort 작업을 진행(nlogn)
	모든 정점을 연결할 필요가 없음
	결론은 s정점과 t 정점이 연결된다는 거임.

	단순히 그럼 s에서 t까지의 거리를 구할 때 가중치 재면 되지 않을까
*/
using namespace std;
int n, m;
typedef struct edge {
	int dist,v;
}edge;
struct cmp {
	bool operator()(edge a, edge b) {
		return a.dist > b.dist; //오름차순 나열
	}
};
map<int, vector<pair<int, int>>>graph;
int dist[5001];
void connect_edge(int cur) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
	dist[cur] = 0;
	priority_queue<edge,vector<edge>,cmp>loc;
	loc.push({ 0,cur });
	while (!loc.empty()) {
		auto value = loc.top(); loc.pop();
		for (auto next : graph[value.v]) {
			if (dist[next.first] > next.second + value.dist) {
				dist[next.first] = next.second + value.dist;
				loc.push({ dist[next.first],next.first });
			}
		}
	}
}
int main() {
	fast;
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
		graph[b].push_back({ a,c });
	}
	int s, t;
	cin >> s >> t;
	connect_edge(s);
	cout << dist[t];
	return 0;
}