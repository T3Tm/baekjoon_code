#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/14620
	꽃길
	1. 씨앗을 3개를 뿌린다.
	2. 뿌린 씨앗을 4갈래로 뿌린다.
	3. 뿌릴 때 겹치는 부분이 나오면 씨앗을 다시 뿌린다.
	4. 4갈래로 성공적으로 뿌려지면 answer에 최솟값을 담는다.
*/
using namespace std;
int n,answer=INT_MAX;
vector<vector<int>>graph;
int visited[12][12];
bool comfirm(int row, int column) {
	if (visited[row][column - 1])return true;
	if (visited[row][column + 1])return true;
	if (visited[row - 1][column])return true;
	if (visited[row + 1][column])return true;
	return false;
}
void spread(int row, int column) {
	visited[row][column - 1] = 1;
	visited[row][column + 1] = 1;
	visited[row - 1][column] = 1;
	visited[row + 1][column] = 1;
}
void reset(int row, int column) {
	visited[row][column] = 0;
	visited[row][column - 1] = 0;
	visited[row][column + 1] = 0;
	visited[row - 1][column] = 0;
	visited[row + 1][column] = 0;
}
void sow(int depth) {
	if (depth == 3) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j])sum += graph[i][j];
			}
		}
		answer = min(answer, sum);
		return;
	}
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			if (visited[i][j] || comfirm(i,j))continue;
			visited[i][j] = 1;
			spread(i, j);
			sow(depth + 1);
			reset(i, j);
		}
	}
}
int main() {
	fast;
	cin >> n;
	graph.resize(n, vector<int>(n,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	sow(0);
	cout << answer;
	return 0;
}