#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    2615 오목
    오른쪽,아래,오른쪽 대각선
    방향없을 때:0
    오른쪽 : 1
    아래 : 2
    오아대 : 3
    오위대 : 4
*/
using namespace std;
int dx[] = {0,1,1,1};
int dy[] = {1,0,1,-1};
vector<vector<int>>graph(19,vector<int>(19,0));
int visited[20][20][5];
bool Omok(int x,int y,int depth,int view){
    bool flag=false;
    if(!view){
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0 || nx>=19 || ny<0 || ny>=19)continue;
            if(visited[nx][ny][i+1])continue;
            if(graph[nx][ny]==graph[x][y]){
                visited[nx][ny][i+1]=1;
                flag=Omok(nx,ny,depth+1,i+1);
                if(flag)return true;
            }
        }
    }else{//방향이 정해졌을 때
        int nx=x+dx[view-1];
        int ny=y+dy[view-1];
        if(nx<0 || nx>=19 || ny<0 || ny>=19){
            if(depth == 5){
                if(view == 4){
                    cout << graph[x][y] << endl;
                    cout << x+1 << " " << y+1;
                    exit(0);
                }else{
                    return true;
                }
            }
            return false;
        }
        if(visited[nx][ny][view])return false;
        if(graph[nx][ny]==graph[x][y]){//나랑 맞을 때
            visited[nx][ny][view]=1;
            flag=Omok(nx,ny,depth+1,view);
        }else{//맞지 않을떄
            if(depth == 5){
                if(view == 4){
                    cout << graph[x][y] << endl;
                    cout << x+1 << " " << y+1;
                    exit(0);
                }else{
                    return true;
                }
            }
        }
    }
    return flag;
}
int main(){
    fast;
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            cin>>graph[i][j];
        }
    }
    for(int i=0;i<19;i++){
        for(int j=0;j<19;j++){
            if(graph[i][j]){
                if(Omok(i,j,1,0)){
                    cout << graph[i][j] << endl;
                    cout << i+1 << " " << j+1;
                    exit(0);
                }
            }
        }
    }
    cout << 0;
    return 0;
}