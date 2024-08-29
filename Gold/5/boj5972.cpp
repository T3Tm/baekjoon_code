#include<bits/stdc++.h>

using namespace std;
int dist[50002];

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n+1);

    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    priority_queue<pair<int,int>> q;
    q.push({0, 1});

    while(!q.empty()){
        auto [value, cur] = q.top();q.pop();
        if(dist[cur] < -value)continue;
        for(auto &[next, cost]: graph[cur]){
            if(dist[next] > cost - value){
                dist[next] = cost - value;
                q.push({-dist[next], next});
            }
        }
    }
    cout << dist[n];
    
    return 0;
}