#include <bits/stdc++.h>
using namespace std;
int height[50002];//각 노드의 높이 
int parent[50002][16];

vector<vector<int>>graph;
void dfs(int cur, int p){
	parent[cur][0] = p;
	height[cur] = height[p] + 1;
	for(auto &next: graph[cur]){
		if(next == p)continue;
		dfs(next, cur);
	}
}
int main(){
	cin.tie(0) -> ios::sync_with_stdio(0);
	int n;cin >> n;
	graph.resize(n+1);
	for(int i=0;i<n-1;i++){
		int a,b;cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1,0);
	
	//i번 부터 시작해서 넣어주기
	for(int j=1;(1 << j)<n;j++){//2^1승을 알기 위해서는 
		for(int i=1;i<=n;i++){
			parent[i][j] = 	parent[parent[i][j-1]][j-1];
		}
	}
	
	
	int m;cin >> m;
	while(m--){
		int a,b;cin >> a >>b;
		if(height[a] < height[b])swap(a,b);

		int d = 0;
		while((1 << (d+1)) <= height[a])d++;

		for(int i=d; i>=0;i--){
			if(height[a] - height[b] >= 1 << i){
				a = parent[a][i];
			}
		}

		for(int i=d; i>=0;i--){
			if(parent[b][i] != 0 && parent[b][i] != parent[a][i]){
				a = parent[a][i];
				b = parent[b][i];
			}
		}
		if(a==b)cout << a << '\n';
		else cout << parent[a][0] << '\n';
	}
	return 0;
}