#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    int board[52][52]{};
    for(int i=0;i<n;i++){
        string a;cin >> a;
        for(int j=0;j<n;j++){
            board[i][j] = a[j] - '0';
        }
    }
    // 0-1 bfs로 돌리면 된다.
    
    int visited[52][52];
    memset(visited,-1,sizeof visited);

    deque<pair<int,int>>q;
    q.push_back({0,0});
    visited[0][0] = 0;


    int dx[]{0,0,1,-1};
    int dy[]{1,-1,0,0};
    while(!q.empty()){
        auto [x,y] = q.front();q.pop_front();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny>=n)continue;
            if(visited[nx][ny]!=-1)continue;
            
            if(board[nx][ny]){
                visited[nx][ny] = visited[x][y];
                q.push_front({nx,ny});
            }else{
                visited[nx][ny] = visited[x][y] + 1;
                q.push_back({nx,ny});
            }
        }
    }
    cout << visited[n-1][n-1];
    return 0;
}