#include <bits/stdc++.h>
using namespace std;
int n,m,d;
int board[16][16],cache[16][16];
int monster;
int result;

void arrCopy(int src[][16], int dst[][16]){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dst[i][j] = src[i][j];
        }
    }
}
void towerDefense(int pick[]){
    
    //궁수들이 공격한다.

    //거리가 D이하 중 가장 가까운 적 (가장 왼쪽의 적) column이 가장 작으면 됨.

    //공격 받으면 해당 적은 죽음.
    
    int Monster{monster};//
    int time{n};//
    while(Monster && time){
        //첫 번째 열에 있는 아이부터 공격
        stack<pair<int,int>>hit;//공격 받은 아이들 넣어놓기
        
        for(int repeat{};repeat<3;repeat++){
            int archerx = n;
            int archery = pick[repeat];

            int nowx = 999, nowy = 999;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(abs(archerx - i) + abs(archery - j) > d)continue;//애초에 공격이 불가
                    int monsterDist = abs(archerx - i) + abs(archery - j);
                    int nowDist = abs(archerx - nowx) + abs(archery - nowy);
                    if(board[i][j]){//적이 있을 때
                        if(monsterDist < nowDist){
                            nowx = i;
                            nowy = j;
                        }
                        else if(monsterDist == nowDist && j < nowy){//이러면 y좌표가 더 작은지 확인
                            nowx = i;
                            nowy = j;
                        }
                    }        
                }
            }
            if(nowx != 999)hit.push({nowx, nowy});
        }
        

        while(!hit.empty()){
            auto [x,y] = hit.top();
            hit.pop();
            if(board[x][y])Monster--;//죽이기
            board[x][y] = 0;
        }

        //한 칸씩 다 내리기
        for(int j=0;j<m;j++){
            for(int i=n-1;i>0;i--){
                board[i][j] = board[i-1][j];//하나씩 값 내리기
            }
            board[0][j] = 0;//값 내렸음
        }
        time--;
    }
    result = max(result,monster - Monster);
    arrCopy(cache,board);
}
void pickUpArcher(int depth,int pre, int pick[]){
    if(depth == 3){//종료 조건
        towerDefense(pick);//
        return;
    }
    for(int i=pre;i<m;i++){
        pick[depth] = i;
        pickUpArcher(depth + 1,i + 1,pick);
    }
}
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    cin >> n >> m >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            monster+=board[i][j];
            cache[i][j] = board[i][j];
        }
    }
    
    //일단 궁수들의 자리를 뽑는다.
    int pick[4]{};//각 궁수들의 자리를 넣기
    pickUpArcher(0,0,pick);
    //시뮬레이션을 돌린다.

    //해당 결과를 저장.
    //455가지의 경우의 수 
    cout << result;
    return 0;
}