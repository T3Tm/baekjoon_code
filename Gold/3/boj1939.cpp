#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n,m;cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n+1);
    
    for(int i=0;i<m;i++){
        int a,b,c;cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }

    int start,target;cin >> start >> target;

    priority_queue<pair<int,int>>q;
    
    int dist[100002]{};
    dist[start] = INF;
    q.push({INF, start});

    while(!q.empty()){
        auto [value, cur] = q.top();q.pop();

        if(dist[cur] > value)continue;//더이상 갈 필요가 없음
        for(auto &[next, nextValue]:graph[cur]){
            if(dist[next] < min(value, nextValue)){
                dist[next] = min(value, nextValue);
                q.push({dist[next], next});
            }
        }
    }

    cout << dist[target];
    return 0;
}