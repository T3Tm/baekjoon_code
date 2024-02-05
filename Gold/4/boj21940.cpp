#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
  https://www.acmicpc.net/problem/21940
  21940�� ������� ������
  ���ͽ�Ʈ�� ����

*/
using namespace std;
int n, m, k;
map<int, map<int, int>>graph;
int dist[202][202];
int arr[202];
void middle(int start) {
	priority_queue<pair<int, int>>mid;
	dist[start][start] = 0;
	mid.push({ 0,start });
	while (!mid.empty()) {
		auto [cost, cur] = mid.top(); mid.pop();//���� �߿��� �ּҸ� 
		for (auto [next, nextc] : graph[cur]) {
			if (dist[start][next] > -cost + nextc) {
				dist[start][next] = -cost + nextc;
				mid.push({ -dist[start][next] ,next });
			}
		}
	}
}
void solve() {
	for (int i = 0; i < n; i++) {//40,000
		for (int j = 0; j < n; j++) {
			dist[i][j] = INT_MAX;
		}
	}
	for (int i = 0; i < n; i++) {//55,720,000
		middle(i);//VlogE 3000
	}
	vector<int>result;
	int minvalue = INT_MAX;
	for (int i = 0; i < n; i++) {//40,000
		int tmp = 0;
		for (int j = 0; j < k; j++) {
			tmp = max(tmp, dist[arr[j]][i] + dist[i][arr[j]]);
		}
		//�ִ��� �պ� �ð� ���� ����.
		if (minvalue > tmp) {
			minvalue = tmp;
			result.clear();
			result.push_back(i + 1);
		}
		else if (minvalue == tmp) {
			result.push_back(i + 1);
		}
	}
	for_each(result.begin(), result.end(), [](int& t) {cout << t << ' '; });
}
int main() {
	fast;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, t; cin >> a >> b >> t;
		graph[a - 1][b - 1] = t;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	solve();
	return 0;
}