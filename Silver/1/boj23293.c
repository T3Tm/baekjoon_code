#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/23293
 23293번 아주 서바이벌
 총 53개의 지역 존재
 1번 지역에서 출발한다.
 플레이어:
    1. 이동
    2. 획득
    3. 조합
    4. 공격
 
 부정행위:
    1. 플레이어가 현재 위치한 지역에서 얻을 수 없는 소재 아이템 획득
    2. 플레이어가 가지고 있지 않은 소재 아이템 사용해 조합
    3. 플레이어가 다른 지역에 있는 상대 플레이어 공격
 
 1. 이동 : 다른 위치로 이동
 2. 획득 : 현재 위치한 지역 x 지역의 아이템만 획득가능
    1. 여러 번 획득 가능
 3. 조합 : 서로 다른 종류의 두 소재 아이템을 1개씩 사용해 장비를 만듦
 4. 공격 : 같은 위치에 있는 사람들끼리만 공격 가능
 */
typedef struct player{
    int item[54],x;//아이템 존재 여부, 현재 위치
    bool ban;
}player;
int t,n;
player players[100002];
void __init__(int n){
    for(int i=1;i<=n;i++){
        players[i].x=1;//현재 위치는 1에서 시작
    }
}
int log_t[200003];
int ban_player;
main(){scanf("%d %d",&t,&n),__init__(n);
    int log_t_idx=0;
    while(t--){
        int num,p,c;
        char a;scanf("%d %d %c %d",&num,&p,&a,&c);
        if(a=='M')players[p].x=c;
        else if(a=='F'){
            if(players[p].x!=c){//오류임.
                log_t[log_t_idx++]=num;
            }
            players[p].item[c]++;//부정행위라도 아이템은 얻어야됨.
        }else if(a=='C'){
            int temp;scanf("%d",&temp);//아이템 두개 이기에.
            if(!players[p].item[c] || !players[p].item[temp]){
                log_t[log_t_idx++]=num;
            }
            if(players[p].item[c])players[p].item[c]--;
            if(players[p].item[temp])players[p].item[temp]--;
        }else{//공격
            if(players[p].x != players[c].x){
                log_t[log_t_idx++]=num;
                if(!players[p].ban)ban_player++;
                players[p].ban=1;
            }
        }
    }
    printf("%d\n",log_t_idx );
    for(int i=0;i<log_t_idx;i++){
        printf("%d ",log_t[i]);
    }
    if(log_t_idx)printf("\n");
    printf("%d\n",ban_player);
    for(int i=1;i<=n;i++){
        if(players[i].ban)printf("%d ",i);
    }
}