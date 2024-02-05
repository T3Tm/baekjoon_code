//
//  main.c
//  baekjoon
//
//  Created by 최지훈 on 2023/06/14.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/23973
 23973번 표적지 옮기기
 0,0 -> 9,9
 0,1 -> 9,8
 0,2 -> 9,7
 0,3 -> 9,6
 2,0 -> 7,9
 */
int n,m;
char board[2502][2502];
char temp[2502];
int score(int x,int y){
    if(x==0 || x==18 || y==0 || y==18)return 1;
    else if(x==1 || x==17 || y == 1 || y==17)return 2;
    else if(x==2 || x==16 || y == 2 || y==16)return 3;
    else if(x==3 || x==15 || y == 3 || y==15)return 4;
    else if(x==4 || x==14 || y == 4 || y==14)return 5;
    else if(x==5 || x==13 || y == 5 || y==13)return 6;
    else if(x==6 || x==12 || y == 6 || y==12)return 7;
    else if(x==7 || x==11 || y == 7 || y==11)return 8;
    else if(x==8 || x==10 || y == 8 || y==10)return 9;
    return 10;
}
bool starting(int x,int y){
    //x,y
    //board의 값에 따라 한번씩 나오는 경우가 있으면 1보내주면 된다.
    int cnt[12]={};
    for(int i=0,inx=x-9;i<19;i++,inx++){
        for(int j=0,iny=y-9;j<19;j++,iny++){
            if(inx<0 || inx>=n || iny<0 || iny>=m)continue;
            if(board[inx][iny]=='1'){
                int number=score(i,j);
                cnt[number]++;
                if(cnt[number]>=2)return 0;
            }
        }
    }
    for(int i=1;i<=10;i++){
        if(cnt[i]<1)return 0;
    }
    return 1;
}
main(){scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",temp),strcpy(board[i],temp);
    //표적지의 중심이 n,m까지 갈 수 있음
    for(int i=0;i<n;i++){//2500
        for(int j=0;j<m;j++){//2500
            if(board[i][j]=='1' && starting(i,j)){//최대 10만번 들어감.
                printf("%d %d",i,j);
                exit(0);
            }
        }
    }
    printf("-1");
}
