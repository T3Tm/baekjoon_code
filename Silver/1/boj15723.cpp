#include <bits/stdc++.h>
#define endl "\n";
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
/*
	https://www.acmicpc.net/problem/15723
	n단 논법
*/
using namespace std;
map<char, vector<char>>graph;
int answer;
void dfs(char cur,int visit[],int target) {
	visit[cur-'a'] = 1;
	if (cur == target) {
		answer = 1;
		return;
	}
	for (char next : graph[cur]) {
		if (!visit[next-'a']) {
			dfs(next, visit,target);
		}
	}
}
int main() {
	fast;
	int n, m;
	cin >> n;
	cin.ignore();
	while (n--) {
		string temp;
		getline(cin, temp);
		graph[temp[0]].push_back(temp.back());
	}
	cin >> m;
	cin.ignore();
	while (m--) {
		int visited[27] = { 0 };
		string temp;
		getline(cin, temp);
		answer = 0;
		dfs(temp[0], visited, temp.back());
		if (answer) {
			cout << "T" << endl;
		}
		else cout << "F" << endl;
	}
	return 0;
}