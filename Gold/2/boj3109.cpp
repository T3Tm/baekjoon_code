#include <bits/stdc++.h>
using namespace std;
int r,c;
char board[10002][502];
bool visited[10002][502];
int dx[]{-1,0,1};//대각선 위, 중간 ,아래
int dy[]{1,1,1};
void dfs(int x, int y, bool & flag){
    visited[x][y] = 1;
    if(flag)return;
    if(y == c-1){
        flag = true;
        return;
    }

    for(int i=0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >=r || ny < 0 || ny >=c)continue ;
        if(visited[nx][ny] || board[nx][ny] == 'x')continue;
        dfs(nx,ny,flag);
        if(flag)return;
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> r >> c;
    //dfs를 돌리는데, 탐색 순서를 맨 위, 중간, 아래로 탐색 순서를 고정
    //그럼 최대 개수가 나옴
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
        }
    }

    int result{};    
    for(int row=0;row<r;row++){
        //맨 처음 열부터 탐색 시작
        bool flag{};
        dfs(row,0,flag);
        result += flag;
    }

    cout << result;
    return 0;
}