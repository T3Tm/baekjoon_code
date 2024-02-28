#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
/*
    https://www.acmicpc.net/problem/9376
    9376번 탈옥
*/
int n,m;
vector<string>board;
int visited1[102][102];
int visited2[102][102];
int visited3[102][102];
void input(){
    cin >> n >> m;
    board = vector<string>(n);
    for(auto&row:board)cin >> row;
}
struct loc{
    int x,y;
    std::size_t operator () (loc const &pair) const
    {
        std::size_t h1 = std::hash<int32_t>()(pair.x);
        std::size_t h2 = std::hash<int32_t>()(pair.y);
        return h1 ^ h2;
    }
};
bool operator==(const loc&a, const loc&b){
    return a.x ==b.x && a.y == b.y;
}
int dx[]{0,0,1,-1};
int dy[]{1,-1,0,0};
vector<loc> prison;
unordered_set<loc,loc>candidate;
int previous = 0;
int bfs(int number,int visited[102][102]){
    memset(visited,0x3f,sizeof(int)*(102*102));
    queue<loc>q;
    for(;previous <number;previous++){
        q.push(prison[previous]);
        visited[prison[previous].x][prison[previous].y] =(board[prison[previous].x][prison[previous].y] == '#' ? 1 : 0);
    }
    int ret = 0x3f3f3f3f;
    while(!q.empty()){
        auto [x,y] = q.front();
        int plus = 0;
        if(board[x][y] == '#')plus++;
        ret = min(ret, visited3[x][y] + visited2[x][y] + visited1[x][y] - 2*plus);
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int plus = 0;
            if(nx < 0 || nx >=n || ny < 0 || ny >=m){
                int size = candidate.size();
                candidate.insert({x,y});
                if(size != candidate.size()){
                    prison.push_back({x,y});
                }
                continue;
            }
            if(board[nx][ny] == '*')continue;
            if(board[nx][ny] == '#')plus = 1;
            if(visited[nx][ny] > visited[x][y] + plus){
                visited[nx][ny] = visited[x][y] + plus;
                q.push({nx,ny});
            }
        }
    }
    for(int i=2;i+1<prison.size();i++){
        if(visited1[prison[i].x][prison[i].y]==0x3f3f3f3f)continue;
        for(int j=i+1;j<prison.size();j++){
            if(visited2[prison[j].x][prison[j].y]==0x3f3f3f3f)continue;
            ret = min(ret, visited1[prison[i].x][prison[i].y] + visited2[prison[j].x][prison[j].y]);
        }
    }
    return ret;
}
void solve(){
    int t;cin >> t;
    while(t--){
        input();
        prison = vector<loc>(2,{0,0});
        previous = 0;
        candidate = unordered_set<loc,loc>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == '$'){
                    if(prison[0].x == 0)prison[0] = {i,j};
                    else prison[1] = {i,j};
                }
            }
        }
        bfs(1,visited1);
        bfs(2,visited2);
        cout << bfs((int)prison.size(),visited3) << endl;
    }
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(0);
    solve();
}