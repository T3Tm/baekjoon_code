#include <stdio.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/2564
 2564번 경비원
*/
typedef struct loc{
    int see,y;
}loc;
int x,y;//블록 가로,세로
int t;//상점의 개수
int board[102][102];
int visited[102][102];
loc my;
int convert[5];
long long cnt;
main(){scanf("%d %d %d",&y,&x,&t);
    convert[2]=x,convert[4]=y;
    for(int i=0,q,w;i<t;i++){
        scanf("%d %d",&q,&w);//방향, 떨어진 거리
        if(q==1 || q==2)board[convert[q]][w]++;//거리에 더해주기
        else board[w][convert[q]]++;
    }
    scanf("%d %d",&my.see,&my.y);
    int tempcnt=0,temp_x,temp_y;
    if(my.see==1 || my.see==2){
        temp_x=convert[my.see];
        temp_y=my.y;
    }else{
        temp_y=convert[my.see];
        temp_x=my.y;
    }
    int temp_cnt=x+y+1;
    int move_cnt=0;
    while(temp_cnt){//left
        if(board[temp_x][temp_y])cnt+=move_cnt;
        visited[temp_x][temp_y]=1;
        
        if(temp_y==0 && temp_x)temp_x--;
        else if(temp_y==y && temp_x<x)temp_x++;
        else if(!temp_x)temp_y++;
        else if(temp_x==x)temp_y--;
        temp_cnt--;
        move_cnt++;
    }
    temp_cnt=x+y+1,move_cnt=0;
    if(my.see==1 || my.see==2){
        temp_x=convert[my.see];
        temp_y=my.y;
    }else{
        temp_y=convert[my.see];
        temp_x=my.y;
    }
    while(temp_cnt){//right
        if(board[temp_x][temp_y] && !visited[temp_x][temp_y])cnt+=move_cnt;
        if(temp_y==0 && temp_x<x)temp_x++;
        else if(temp_y==y && temp_x)temp_x--;
        else if(!temp_x)temp_y--;
        else if(temp_x==x)temp_y++;
        temp_cnt--;
        move_cnt++;
    }
    printf("%lld",cnt);
}