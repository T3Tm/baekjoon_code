#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph(51);
int root;
int removes;
int result;
void dfs(int cur){
    if(cur == removes)return;
    if(!graph[cur].size())result++;
    else if(graph[cur].size() == 1 && graph[cur][0] == removes){
        result++;
    }
    for(auto &next: graph[cur]){
        dfs(next);
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    for(int i=0,a;i<n;i++){
        cin >> a;
        if(a == -1)root = i;
        else{
            graph[a].push_back(i);
        }
    }
    cin >> removes;
    dfs(root);//루트부터 시작해서 들어갑시다.
    cout << result;
    return 0;
}