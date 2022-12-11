#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/21278
	호석이 두 마리 치킨
	A <-> B 양방향 도로
	2개의 정점을 골라야 한다.

	N개가 있을 때 일단 플로이드 돌린다.
	인접행렬에 대한 모든 정점에서 다른 정점까지의 최단거리를 구할 수 있음
	시복 (n^3) => 10^6
	N에서 2개를 뽑습니다. 
	100C2 => 4950번을 비교해서 최소로 나오는 것이 바뀔 때만 바꾼다.

	같을 때는 바꾸지 않는다.
*/
using namespace std;
long long dist[102][102];
int main() {
	fast;
	int n, m;
	int result[3] = { 0,0,INT_MAX };//건물 번호,거리;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = INT_MAX;
		}
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;//양방향 도로
		dist[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {//k를 지날때 
		for (int i = 1; i <= n; i++) {//i에서 j를 간다
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {//i에서 j를 가는 거리보다 k를 경유하는 것이 더 짧다.
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	vector<int>pick(n - 2, 0);
	for (int i = 0; i < 2; i++)pick.push_back(1);
	do {
		int total = 0;
		deque<int>house;
		deque<int>chickenHouse;
		for (int i = 0; i < n; i++) {
			if (pick[i]) {
				chickenHouse.push_front(n-i);
			}
			else {
				house.push_front(n-i);
			}
		}
		for (auto vertex : house) {
			total += min(dist[vertex][chickenHouse[0]], dist[vertex][chickenHouse[1]]) * 2;
		}
		if (total < result[2]) {
			result[0] = chickenHouse[0];
			result[1] = chickenHouse[1];
			result[2] = total;
		}
	} while (next_permutation(pick.begin(), pick.end()));
	for (auto value : result) {
		cout << value << " ";
	}
	return 0;
}