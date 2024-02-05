#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
/*
	https://www.acmicpc.net/problem/2250
	트리의 높이와 너비
	루트 노드는 왼쪽 오른쪽으로 나아 가야 하므로 
	left right가 -1이 아니어야함.

*/
vector<pair<int, int>>graph;
vector<pair<int, int>>result(10001, { 10001,1 });
int Find[10001] = { 0 };
int column = 1;
void inorder(int depth, int cur) {
	if (graph[cur].first != -1) {
		inorder(depth + 1, graph[cur].first);
	}
	result[depth].first=min(result[depth].first,column);
	result[depth].second = max(result[depth].second, column++);
	if (graph[cur].second != -1) {
		inorder(depth + 1, graph[cur].second);
	}
}
int main() {
	fast;
	int n,node,left,right;
	cin >> n;
	graph.resize(n+1, { -1,-1 });
	for(int i=0;i<n;i++){
		cin >> node >> left >> right;
		Find[left] = 1;
		Find[right] = 1;
		graph[node].first = left;
		graph[node].second = right;
	}
	int root,level, width = 0;
	for (int i = 1; i <= n; i++) {
		if (!Find[i])root = i;
	}
	inorder(1, root); // 루트 노드는 1이 아닐 수 있다
	for (int i = 1; i <= n; i++) {
		if (result[i].second - result[i].first + 1 > width) {
			width = result[i].second - result[i].first + 1;
			level = i;
		}
	}
	cout << level << " " << width;
	return 0;
}