#include <stdbool.h>
/*
 https://www.acmicpc.net/problem/15730
 15730번 수영장 사장님
 
*/
typedef struct myarr{
    int height,result;//블록 높이, 물 높이, 사방면 최솟값
    int four[4];//동,서,남,북
}myarr;
myarr arr[102][102];
int n,m;
int result;
//경계면 체크
bool isBoundary(int x,int y){
    return x==0 || x==n-1 || y==0 || y==m-1;
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
typedef struct loc{
    int x,y;
}loc;
loc query[10002];
int locsize;
bool dfs(int x,int y,int h,int v[][102]){//물이 흐르는지만 알면 됨.
    v[x][y]=1;//방문처리
    query[locsize].x=x;
    query[locsize++].y=y;
    bool flag=1;
    int nextx[4]={};
    int nexty[4]={};
    int size=0;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(h>arr[nx][ny].height){//현재 설정한 물높이보다 다음 높이가 큰지 판단
            if(v[nx][ny]==1)continue;
            if(v[nx][ny]==-1)return 0;
            if(isBoundary(nx, ny)){//밖으로 나가네?
                flag=size=0;
                break;
            }
            nextx[size]=nx;
            nexty[size++]=ny;
        }
    }
    for(int i=0;i<size;i++){
        int nx=nextx[i];
        int ny=nexty[i];
        flag=dfs(nx,ny,h,v);
        if(!flag)break;
    }
    return flag;
}
//해당 높이로 result계산해보기
void spread_Water(int height){
    int visited[102][102]={};
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(height<=arr[i][j].height){//설정한 물 높이보다 블럭높이가 높거나 같으면 그냥 못들어감.
                visited[i][j]=1;//어차피 안 되니까 방문처리
            }else{//블럭 높이보다 물 높이가 크니까 물이 찰 수 있음.
                //물이 다른쪽으로 빠지는지 확인만 해주면 됨.
                //오른쪽,왼쪽,위,아래로 물이 빠지는 확인하고 빠진다면 그 빠지는 곳까지 같이 계산하면 된다.
                if(visited[i][j]==0){
                    locsize=0;
                    bool flag=dfs(i,j,height,visited);
                    for(int z=0;z<locsize;z++){//지금 좌표들 다 처리
                        int x=query[z].x;
                        int y=query[z].y;
                        if(flag)arr[x][y].result=height;
                        else visited[x][y]=-1;
                    }
                    
                }
            }
        }
    }
}
void solve(){
    int maxheight=0;
    //1. 최대 물 높이 확인하기.
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(maxheight<arr[i][j].height)maxheight=arr[i][j].height;
        }
    }
    
    //2. 그 최대 높이까지 물 하나씩 설정해보기
    for(int waterheight=0;waterheight<=maxheight;waterheight++){
        spread_Water(waterheight);
    }
    
    //3.물 계산
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(arr[i][j].result)result+=arr[i][j].result-arr[i][j].height;
        }
    }
    
    printf("%d",result);//결과 출력
}
main(){scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&arr[i][j].height);
    solve();
}
