#include <stdbool.h>
/*
 https://www.acmicpc.net/problem/2931
 2931번 가스관
 1.출력 : 지워진 블록의 행과 열 위치를 출력하고, 무슨 블럭이었는지 출력하여라.
 
 1.모든 칸을 25*25*7에서 특정 칸으로 대체
 2.그 칸으로 대입해봤을 때 이어지는지 확인
 3.25*25를 탐색
 
 1. 25*25 탐색
 2. 7개로 바꾸기
 3. 바꾼 거 맞는지 그래프 탐색
 무조건 정답이 있는 게 있음. 그렇기에 가능
 브루트 포스 + 시뮬레이션
 
 어디로 가고 있었는지 정보를 추가적으로 갖고 있어야 된다.
*/
int r,c;
char board[27][27];
int x,y;
char searchchar[]="|-+1234";
char see=' ';
void init(){//초기 부분 설정해줘야됨.
    if(y-1>0 && board[x][y-1]=='-' ||board[x][y-1]=='1' || board[x][y-1]=='+'|| board[x][y-1]=='2')see='<';//왼쪽으로 가고 있던 중
    else if(x-1>0 && board[x-1][y]=='|' ||board[x-1][y]=='+' || board[x-1][y]=='1'|| board[x-1][y]=='4')see='u';//위로 가고 있던 중
    else if(x+1<r && board[x+1][y]=='|' ||board[x+1][y]=='+' || board[x+1][y]=='2'|| board[x+1][y]=='3')see='d';//아래로 가던 중
    else if(y+1<c && board[x][y+1]=='-' ||board[x][y+1]=='+' || board[x][y+1]=='3'|| board[x][y+1]=='4')see='>';//오른쪽으로 가고 있던 중
    
    
    if(see=='>')y++;
    else if(see=='<')y--;
    else if(see=='u')x--;
    else if(see=='d')x++;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool moving(int *cur_x,int* cur_y){//방향도 바꿔줘야됨.
    int c_x=*cur_x,c_y=*cur_y;//좌표 일단 복사해놓기.
    if(board[c_x][c_y]=='|'){
        if(see=='u'){
            c_x=c_x+dx[3];
            c_y=c_y+dy[3];
        }else if(see=='d'){
            c_x=c_x+dx[2];
            c_y=c_y+dy[2];
        }else return false;
    }else if(board[c_x][c_y]=='-'){
        if(see=='<'){
            c_x=c_x+dx[1];
            c_y=c_y+dy[1];
        }else if(see=='>'){
            c_x=c_x+dx[0];
            c_y=c_y+dy[0];
        }else return false;
    }else if(board[c_x][c_y]=='+'){
        if(see=='<'){
            c_x=c_x+dx[1];
            c_y=c_y+dy[1];
        }else if(see=='>'){
            c_x=c_x+dx[0];
            c_y=c_y+dy[0];
        }else if(see=='u'){
            c_x=c_x+dx[3];
            c_y=c_y+dy[3];
        }else if(see=='d'){
            c_x=c_x+dx[2];
            c_y=c_y+dy[2];
        }else return false;
    }else if(board[c_x][c_y]=='1'){
        if(see=='<'){
            see='d';
        c_x=c_x+dx[2];
        c_y=c_y+dy[2];
        }else if(see=='u'){
            c_x=c_x+dx[0];
            c_y=c_y+dy[0];
            see='>';
        }else return false;
    }else if(board[c_x][c_y]=='2'){
        if(see=='<'){
            see='u';
        c_x=c_x+dx[3];
        c_y=c_y+dy[3];
        }else if(see=='d'){
            c_x=c_x+dx[0];
            c_y=c_y+dy[0];
            see='>';
        }else return false;
    }else if(board[c_x][c_y]=='3'){
        if(see=='>'){
            see='u';
        c_x=c_x+dx[3];
        c_y=c_y+dy[3];
        }else if(see=='d'){
            c_x=c_x+dx[1];
            c_y=c_y+dy[1];
            see='<';
        }else return false;
    }else if(board[c_x][c_y]=='4'){
        if(see=='>'){
            see='d';
        c_x=c_x+dx[2];
        c_y=c_y+dy[2];
        }else if(see=='u'){
            c_x=c_x+dx[1];
            c_y=c_y+dy[1];
            see='<';
        }else return false;
    }else return false;//.이기에 안됨.
    
    
    if(c_x<0 || c_x>=r || c_y < 0 || c_y>=c)return false;//좌표 넘어가면 안됨.
    if(see=='<'){
        if(board[c_x][c_y]=='|' || board[c_x][c_y]=='3' ||board[c_x][c_y]=='4')return false;
    }else if(see=='>'){
        if(board[c_x][c_y]=='|' || board[c_x][c_y]=='1' ||board[c_x][c_y]=='2')return false;
    }else if(see=='u'){
        if(board[c_x][c_y]=='-' || board[c_x][c_y]=='2' ||board[c_x][c_y]=='3')return false;
    }else if(see=='d'){
        if(board[c_x][c_y]=='-' || board[c_x][c_y]=='1' ||board[c_x][c_y]=='4')return false;
    }else return false;
    *cur_x=c_x,*cur_y=c_y;
    return true;
}
bool gas(){
    int cur_x=x,cur_y=y;
    if(see==' ')init();//좌표 설정했는데 못했을 시에
    if(see==' ')return false;//처음부터 좌표가 이상하네?
    while(1){
        if(moving(&cur_x,&cur_y)){//좌표 움직여주기
            //성공적으로 좌표 움직이기가 됐음.
            if(board[cur_x][cur_y]=='Z')return true;//도착했음.
        }else{//올바르게 안 이어져 있네?
            break;
        }
    }
    return false;
}
void solve(){
    //25*25탐색
    init();//초기 방향과 커서들 어디인지 설정 완료.
    char temp=see;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]!='.')continue;//.인 부분에만 넣을 수 있기 때문
            for(int z=0;searchchar[z];z++){//해당하는 부분만 검색해야됨.
                board[i][j]=searchchar[z];//이것으로 넣고 탐색해보기.
                if(gas()){
                    printf("%d %d %c",i+1,j+1,searchchar[z]);
                    exit(0);//그리고 종료하기.
                }
                see=temp;
            }
        }
    }
}
main(){scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        scanf("%s",board[i]);
        for(int j=0;board[i][j];j++){
            if(board[i][j]=='M')x=i,y=j;//시작 위치 알아내기
        }
    }
    solve();
}
