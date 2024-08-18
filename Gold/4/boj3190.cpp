#include <bits/stdc++.h>
using namespace std;
void turn(int& dir, int plus){//right 1, left 3
    dir = (dir + plus)%4;
}

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n, k,l;cin >> n >> k;
    int board[102][102]{};
    for(int i=0;i<k;i++){
        int a,b;cin >> a >> b;
        board[a][b] = 1;
    }

    deque<pair<int,int>> q;
    cin >> l;
    vector<pair<int,char>> times(l);
    int idx{};
    
    for(auto& [tim, D]: times){
        cin >> tim >> D;
    }
    
    q.push_back({1,1});//시작 지점
    int time{};
    
    int dir = 1;

    int dx[]{-1,0,1,0};
    int dy[]{0,1,0,-1};
    while(1){
        auto [x, y] = q.front();//1. 앞으로 가기.
        int nx =  x + dx[dir];
        int ny = y + dy[dir];
        time++;//시간 증가

        //벽 처리
        if(nx < 1 || nx > n || ny < 1 || ny > n)break;
        //자신의 몸박처리
        bool flag = false;
        for(auto [xx, yy]: q){
            if(xx == nx && yy == ny){
                flag = true;
                break;
            }
        }
        if(flag)break;//박힘
        //괜찮으면 해당 위치에 사과 있는지 처리 
        q.push_front({nx,ny});
        if(!board[nx][ny]){//있으면 nx앞으로 그냥 넣기
            //맨 뒤에 좌표 빼기
            q.pop_back();
        }else{
            board[nx][ny] = 0;//사과 한 번 먹었으면 다시 못 먹어야함 .
        }
        
        //방향 전환
        if(idx < l){
            if(times[idx].first == time){//방향 전환 해야 됨.
                if(times[idx].second == 'D'){
                    turn(dir, 1);
                }else{
                    turn(dir, 3);
                }
                idx++;//방향 처리했으니까 +1
            }
        }
    }
    cout << time;
    return 0;
}