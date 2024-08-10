#include <bits/stdc++.h>
using namespace std;
unordered_map<int,unordered_map<int,int>>graph;
int candidate[102];
int candidateDist[102];
/*
    해당 지점을 무조건 지나가는 최단 거리를 찾아내서 
    1. s -> 목적지 후보들 최단거리 구하기
    ElogV
    
    1. s지점에서 g까지 최단 거리 알아내기 
    2. g -> h까지 가기 O (1)
    3. h -> 목적지 후보까지 최단거리 알아내기
    ElogV

    1. s지점에서 h까지 최단 거리 알아내기
    2. h -> g까지 가기 O (1)
    3. g -> 목적지 후보까지 최단거리 알아내기
    ElogV
    
    3 * ElogV
    혹시 최단거리가 같다면 가능하다는 것!
    하지만 다르다면 불가능

    충분히 가능
*/
void shortDist(int start, int dist[]){
    memset(dist, 0x3f, sizeof(int)*2002);
    dist[start] = 0;
    
    priority_queue<pair<int,int>>q;
    q.push({0,start});
    while(!q.empty()){
        auto [value, v] = q.top();q.pop();
        if(value > dist[v])continue;//최소가 아님
        for(auto &[key, keyValue] : graph[v]){
            if(-value + keyValue < dist[key]){
                dist[key] = -value + keyValue;
                q.push({-dist[key], key});
            }
        }
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int T;cin >> T;
    while(T--){
        int n,m,t;cin >> n >> m >> t;
        int s,g,h;cin >> s >> g >> h;      
        graph.clear(); 

        for(int i=0;i<m;i++){//그래프 연결
            int a,b,d;cin >> a >> b >> d;
            graph[a][b] = d;
            graph[b][a] = d;
        }

        //목적지 후보
        for(int i=0;i<t;i++){
            cin >> candidate[i];
        }
        
        //s부터 short dist 구하기
        int dist[2002];
        shortDist(s,dist);

        //각 후보들의 최단거리 저장해놓기
        for(int i=0;i<t;i++){
            candidateDist[i] = dist[candidate[i]];
        }
        
        set<int>result;
        // 1. s -> g까지 최단거리 
        int s_g = dist[g];//INF라면 더이상 계산할 이유가 없음
        int s_h = dist[h];
        if(s_g != 0x3f3f3f3f){
            s_g += graph[g][h];//g에서 h갈 때
            //h부터 각 목적지까지 최단거리   
            shortDist(h,dist);
            //비교 했을 때 같으면 넣기
            for(int i=0;i<t;i++){
                if(candidateDist[i] == s_g + dist[candidate[i]]){//최단거리로 해당 목적지 가능
                    result.insert(candidate[i]);
                }
            }
        }
        
        if(s_h != 0x3f3f3f3f){
            s_h += graph[g][h];//g에서 h갈 때
            //h부터 각 목적지까지 최단거리   
            shortDist(g,dist);
            //비교 했을 때 같으면 넣기
            for(int i=0;i<t;i++){
                if(candidateDist[i] == s_h + dist[candidate[i]]){//최단거리로 해당 목적지 가능
                    result.insert(candidate[i]);
                }
            }
        }
        //정답 출력
        for(auto& v:result)cout << v << ' ';
        cout << '\n';
    }
    return 0;
}