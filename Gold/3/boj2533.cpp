#include <bits/stdc++.h>
using namespace std;
int dp[1000002][2];
vector<vector<int>> graph;
int sns(int node, bool status, int pre){
	if(dp[node][status]!= -1)return dp[node][status];
	
	dp[node][status] = status;
	//내가 status이기에 
	for(auto&next : graph[node]){//이전에 pre한 것과 달라야 된다.
		//내가 칠했기 때문에 더 작은 값을 더해주면 된다.
		if(next == pre)continue;
		if(status)
			dp[node][status] +=  min(sns(next, 1, node), sns(next, 0, node));
		else //내가 칠해지지 않았음 아래있을 아이들 다 칠해져야함.
			dp[node][status] +=  sns(next,1, node);
	}
	return dp[node][status];//
}
int main()
{
	cin.tie(0)->ios::sync_with_stdio(0);
	int n;
	cin >> n;
	graph.resize(n+1);	
	memset(dp, -1, sizeof dp);
	for (int i{}; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << min(sns(1, 0 , 0), sns(1,1, 0));
	return 0;
}