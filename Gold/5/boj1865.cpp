#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
*	https://www.acmicpc.net/problem/1865
	1865�� ��Ȧ
	N���� ����
	M���� ���ο� W���� ��Ȧ�� �ִ�.
	���δ� �����
	��Ȧ�� �ܹ��� (�ð谡 �Ųٷ� ��..?)

	A�������� �����ؼ� �ð����� ���� �ٽ� A�������� ���ƿ�����,
	������� ������ �ð��� �ǵ��� ������ �ִ��� Ȯ��
	=> ��, ��Ȧ�� Ÿ�� A�������� �� ���� �ִ��� Ȯ���ش޶�� �ų�?

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