#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/21940
  21940번 가운데에서 만나기

  서로 다른 도시에 살고 있음.
  방향 그래프
  A-> B
  B -> A cost 다름
  준형이와 친구들의 왕복시간 들 중
  준형 왕복, 친구들 왕복 최대가 ,  최소가 되는 도시 X를 선택한다.
  
*/
using namespace std;
int n, m,k;
map<int, map<int, int>>graph;
long long dist[202][202];
int arr[202];
void floyid() {
	for (int z = 0; z < n; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][z] + dist[z][j]);
			}
		}
	}
}
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = INT_MAX;
		}
	}
}
void solve() {
	floyid();
	vector<int>result;
	int minvalue = INT_MAX;
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		for (int j = 0; j < k; j++) {
			tmp = max(tmp, (int)(dist[arr[j]][i] + dist[i][arr[j]]));
		}
		//최대의 왕복 시간 갖고 오기.
		if (minvalue > tmp) {
			minvalue = tmp;
			result.clear();
			result.push_back(i+1);
		}
		else if (minvalue == tmp) {
			result.push_back(i+1);
		}
	}
	for (auto& value : result) {
		cout << value << ' ';
	}
}
int main() {
	fast;
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		graph[a-1][b-1] = t;
		dist[a - 1][b - 1] = t;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	solve();
	return 0;
}