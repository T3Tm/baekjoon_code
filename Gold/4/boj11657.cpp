#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
*	https://www.acmicpc.net/problem/11657
	11657번 타임머신
*/
using namespace std;
struct edge {
	int s, e, w;
};
vector<long long> bellman(int start,int n,vector<edge>&road) {
	long long dist[507]; memset(dist, 0x3f, sizeof dist);
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		for (auto [s, e, c]:road) {
			if (dist[s] != 0x3f3f3f3f3f3f3f3f && dist[e] > dist[s] + c) {
				if (i == n - 1)return { -1 };
				dist[e] = dist[s] + c;
			}
		}
	}
	vector<long long>tmp;
	for (int i = 2; i <= n; i++) {
		tmp.push_back((dist[i] == 0x3f3f3f3f3f3f3f3f ? -1 : dist[i]));
	}
	return tmp;
}
int main() {
	fast;
	int n, m; cin >> n >> m;
	vector<edge>road;
	for (int i = 0; i < m; i++) {
		int s, e, t; cin >> s >> e >> t;
		road.push_back({ s,e,t });
	}
	auto v = bellman(1, n, road);
	if (v[0]==-1 && v.size()==1)cout << -1;
	else {
		for (int it : v)cout << it << endl;
	}
	return 0;
}