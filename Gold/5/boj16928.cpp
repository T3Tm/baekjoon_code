#include <bits/stdc++.h>

using namespace std;
// 1칸부터 6칸 까지 갈 수 있음.
// 6칸까지는 미리 넣어놓기
/*
 * 16928번 뱀과 사다리 게임
 */
int main() {
    cin.tie(0)->ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>graph(102,vector<int>());//갈 수 있는 길이 있으면 간다.
    while(n--){
        int a,b;cin >> a >> b;
        graph[a].push_back(b);
    }
    while(m--){
        int a,b;cin >> a >> b;
        graph[a].push_back(b);
    }
    queue<int> loc;
    int visited[102]{};memset(visited,-1,sizeof visited);
    loc.push(1);visited[1]=0;
    while (!loc.empty()){
        auto cur = loc.front();loc.pop();
        for(int i=1;i<7;i++){//1칸부터 6칸 사이로 갈 수 있음
            int next = cur + i;//혹시 여기에 올라갈 수 있는 엘베나 내려가는 엘베 있는지 확인
            if (next > 100) continue;
            if (!graph[next].empty()) next = graph[next].front();

            if (visited[next] != -1)continue;
            visited[next] = visited[cur] + 1;
            loc.push(next);
        }
    }
    cout << visited[100];
    return 0;
}