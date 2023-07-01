#include <stdbool.h>
#include <limits.h>
#define min(a,b)(a>b?b:a)
/*
 https://www.acmicpc.net/problem/17622
 17622번 타일 교체
 0 : 위 오른쪽, 왼쪽 아래
 1 : 위 왼쪽, 오른쪽 아래
 2 : 아래 오른쪽, 왼쪽 위
 3 : 아래 왼쪽, 오른쪽 위
 4 : 위 아래, 아래 위
 5 : 왼쪽 오른쪽, 오른쪽 왼쪽
 
 
 1. 0,0에서 이동시작한다.
 2. 이동을 하다가 이동을 못 한다면 k를 본다. k가 없다면 -1을 저장하면 return을 맞이한다.
 3. k가 있다면 원래 있던 모양 말고 다른 것을 본다.
    3-1. 0
    3-2. 1
    3-3. 2
    3-4. 3
    3-5. 4
    3-6. 5
*/
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,k;
int board[53][53];
bool trans(int *x,int *y,int tile,int* see){//전에 위치 받고, 몇 번인지 받기
    //어디서 왔는지 일단 보고
    //tile이 무엇인지 확인하고 x,y좌표를 어떻게 바꿀지 생각.
    bool flag=0;
    int ret=*see;
    if(!tile){
        if(*see==0){//왼쪽에서 왔음
            flag=1;
            *x=*x+dx[2],*y=*y+dy[2];
            *see=3;
        }else if(*see==2){//위로 올라왔음.
            flag=1;
            *x=*x+dx[0],*y=*y+dy[0];
            *see=1;
        }
    }else if(tile==1){
        if(*see==2){//위로 올라왔음.
            flag=1;
            *x=*x+dx[1],*y=*y+dy[1];
            *see=0;
        }else if(*see==1){//오른쪽에서 왔음.
            flag=1;
            *x=*x+dx[2],*y=*y+dy[2];
            *see=3;
        }
    }else if(tile==2){
        if(*see==3){//아래에서 왔음
            flag=1;
            *x=*x+dx[0],*y=*y+dy[0];
            *see=1;
        }else if(*see==0){//왼쪽에서 왔음
            flag=1;
            *x=*x+dx[3],*y=*y+dy[3];
            *see=2;
        }
    }else if(tile==3){
        if(*see==3){//아래에서 왔음
            flag=1;
            *x=*x+dx[1],*y=*y+dy[1];
            *see=0;
        }else if(*see==1){//오른쪽에서 왔음.
            flag=1;
            *x=*x+dx[3],*y=*y+dy[3];
            *see=2;
        }
    }else if(tile==4){
        if(*see==3){//아래에서 왔음
            flag=1;
            *x=*x+dx[2],*y=*y+dy[2];
        }else if(*see==2){//위에서 왔음.
            flag=1;
            *x=*x+dx[3],*y=*y+dy[3];
        }
    }else if(tile==5){
        if(*see==0){//왼쪽에서 왔음
            flag=1;
            *x=*x+dx[1],*y=*y+dy[1];
        }else if(*see==1){//오른쪽에서 왔음.
            flag=1;
            *x=*x+dx[0],*y=*y+dy[0];
        }
    }
    if(*x==n-1 && *y==n)return true;
    else if(*x<0 || *x>=n || *y<0 || *y>=n)flag=false;
    
    if(!*see){//왼쪽으로 가기
        if(board[*x][*y]==1 || board[*x][*y]==3 || board[*x][*y]==4)flag=false;
    }else if(*see==1){//오른쪽으로 가기
        if(!board[*x][*y] || board[*x][*y]==2 || board[*x][*y]==4)flag=false;
    }else if(*see==2){//위로 가기
        if(board[*x][*y]==2 || board[*x][*y]==3 || board[*x][*y]==5)flag=false;
    }else{//아래로 가기
        if(!board[*x][*y] || board[*x][*y]==1 || board[*x][*y]==5)flag=false;
    }
    
    
    if(!flag)*see=ret;
    return flag;//제대로 반환이 안됨.
}
int result=INT_MAX;
bool bfs(){//좌표를 받아볼까?
    int x=0,y=0,see=1;
    int time=0;
    while(1){
        if(trans(&x,&y,board[x][y],&see))time++;
        else break;
        if(x==n-1 && y==n){
            result=min(result,time);
            return 1;
        }
    }
    return 0;
}
void solve(){
    //일단 bfs를 한 번 돌려서
    if(!k){
        bfs();
    }else{//한 번쯤은 타일 교체해야됨.
        int shorty=2;
        for(int i=0;i<n && shorty;i++){
            for(int j=0;j<n && shorty;j++){
                for(int z=0;z<6;z++){
                    if(board[i][j]==z)continue;
                    int re=board[i][j];
                    board[i][j]=z;
                    if(bfs()){
                        board[i][j]=re;
                        shorty--;
                        break;
                    }
                    board[i][j]=re;
                }
            }
        }
    }
    printf("%d",(result==INT_MAX?-1:result));
}
main(){scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&board[i][j]);//입력 받기
    solve();
}