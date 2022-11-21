#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/21924
	도시 건설
	MST 네
	모든 도로를 최소한의 도로로 연결하는 거니까

	크루스칼 알고리즘 이용하면 될듯.
	크루스칼은 
	union_find + 정렬 알고리즘을 이용한 거임
	union_find는 
	find , union 알고리즘을 이용하는 거임
*/
int parent[100001];//부모 union find 알고리즘 이용할 것
int find(int n) {
	if (parent[n] == -1)return n;
	return parent[n] = find(parent[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return;
	if (b > a)parent[b] = a;
	else parent[a] = b;
}
int main() {
	fast;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)parent[i] = -1;
	priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>city;
	long long total = 0;
	for(int i=0;i<m;i++){
		int a, b, c;
		cin >> a >> b >> c;
		total += c;
		city.push({ c,{a,b} });
	}
	int count = 0;
	for (int i = 0; i < m;i++) {
		auto value=city.top(); city.pop();
		int cost = value.first;
		int v1 = value.second.first;
		int v2 = value.second.second;
		if (find(v1) != find(v2)) {
			merge(v1, v2);
			total -= cost;
			count++;
		}
		if (count == n - 1)break;
	}
	int compare = 1;
	for (int i = 1; i <= n; i++) {
		if (parent[i]==-1) {
			compare--;
		}
	}
	if (compare < 0)total = -1;
	cout << total;
	return 0;
}