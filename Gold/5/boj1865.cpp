#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
*	https://www.acmicpc.net/problem/1865
	1865번 웜홀
	N개의 지점
	M개의 도로와 W개의 웜홀이 있다.
	도로는 양방향
	웜홀은 단방향 (시계가 거꾸로 감..?)

	A지점에서 시작해서 시간여행 시작 다시 A지점으로 돌아왔을때,
	출발했을 때보다 시간이 되돌아 간적이 있는지 확인
	=> 즉, 웜홀을 타서 A지점까지 간 적이 있는지 확인해달라는 거네?

*/
using namespace std;
struct edge {
	int s, e, w;
};
bool bellman(int n, vector<edge>& road) {
	int dist[507] = { 0 };
	for (int i = 0; i < n; i++) {
		for (auto [s, e, c] : road) {
			if (dist[s] != 0x3f3f3f3f && dist[e] > dist[s] + c) {
				if (i == n - 1)return true;
				dist[e] = dist[s] + c;
			}
		}
	}
	return false;
}
int main() {
	fast;
	int t; cin >> t;
	while (t--) {
		int n, m, w; cin >> n >> m >> w;
		vector<edge>road;
		for (int i = 0; i < m; i++) {
			int s, e, t; cin >> s >> e >> t;
			road.push_back({ s,e,t });
			road.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t; cin >> s >> e >> t;
			road.push_back({ s,e,-t });
		}
		if (bellman(n, road))cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}