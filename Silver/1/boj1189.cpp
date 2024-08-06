#include <bits/stdc++.h>
using namespace std;
int ret;
int r,c,k;
int dx[]{0,0,1,-1};
int dy[]{1,-1,0,0};
vector<vector<char>> board;
void dfs(int x, int y, int k, bool avail[][6]){
    if(k == 0){
        if(x == 0 && y == c-1)ret++;
        return;
    }
    avail[x][y] = 1;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
        if(board[nx][ny] == 'T' || avail[nx][ny])continue;
        dfs(nx,ny,k-1,avail);
    }
    avail[x][y] = 0;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> r >> c >> k;
    board.resize(r,vector<char>(c,' '));
    for(auto &row: board)for(auto &column:row)cin >> column;
    
    bool avail[6][6]{};
    dfs(r-1,0,k-1, avail);
    cout <<ret;
    return 0;
}