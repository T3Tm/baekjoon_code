#include <bits/stdc++.h>

using namespace std;
int n,m;
int dp[1002];
int indegree[1002];
int main() {
    cin >> n >> m;
    queue<int>q;
    vector<vector<int>>graph(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }


    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            dp[i] = 1;
        }
    }

    while(!q.empty()){
        int cur = q.front();q.pop();

        for(int next: graph[cur]){
            indegree[next]--;
            dp[next] = max(dp[next], dp[cur]);
            if(!indegree[next]){
                q.push(next);
                dp[next]++;
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << dp[i] << ' ';
    }
    return 0;
}