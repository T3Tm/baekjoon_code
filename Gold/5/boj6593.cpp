#include <bits/stdc++.h>
using namespace std;
char board[32][32][32];
tuple<int,int,int> Find(int l, int r, int c){
    for(int h=0;h<l;h++){
        for(int row=0;row<r;row++){
            for(int column = 0; column < c;column++){
                if(board[h][row][column]=='S'){
                    return {h,row,column};
                }
            }
        }
    }
}


int dz[]{0,0,0,0,1,-1};
int dx[]{0,0,1,-1,0,0};
int dy[]{1,-1,0,0,0,0};
int bfs(int l, int r, int c){
    queue<tuple<int,int,int>> q;
    int visited[l][r][c];
    memset(visited,-1,sizeof visited);
    
    auto[z,x,y] = Find(l,r,c);
    visited[z][x][y] = 0;
    q.push({z,x,y});

    while(!q.empty()){
        auto [z,x,y] = q.front() ;q.pop();

        if(board[z][x][y] == 'E')return visited[z][x][y];
        for(int i=0;i<6;i++){
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nz < 0 || nz >=l || nx < 0 || nx >=r || ny < 0 || ny >=c)continue;
            if(visited[nz][nx][ny]!=-1 || board[nz][nx][ny]=='#')continue;
            visited[nz][nx][ny] = visited[z][x][y]+1;
            q.push({nz,nx,ny});
        }
    }
    return -1;
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    while(1){
        int l,r,c; cin >> l >> r >> c;
        if(!l)break;

        for(int h=0;h<l;h++){
            for(int row=0;row<r;row++){
                for(int column = 0; column < c;column++){
                    cin >> board[h][row][column];
                }
            }
        }

        int ret = bfs(l,r,c);
        if(ret == -1){
            cout << "Trapped!\n";
        }else{
            cout << "Escaped in " << ret <<" minute(s).\n";
        }

    }
    return 0;
}