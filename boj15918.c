#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define ll long long
/*
 https://www.acmicpc.net/problem/15918
 15918번 랭퍼든 수열쟁이야!!
 
 길이가 x랑 y랑 같으려면 거기에는 애초에 숫자가 들어가야 됨.
 
 12*24
 24*12
 */
int n,x,y;
int result[25];
bool avail[13];
ll cnt;
void backtrack(int depth){//깊이, idx
    if(depth == 2*n){//depth
        cnt++;return;
    }
    if(result[depth]){
        backtrack(depth+1);
        return;
    }
    for(int i=1;i<=n;i++){//24번
        if(avail[i] || i+depth+1 >=2*n || result[i+depth+1])continue;
        result[depth] = i;
        result[i+depth+1]=i;
        avail[i]=1;
        backtrack(depth+1);//12번
        result[depth] = 0;
        result[i+depth+1]=0;
        avail[i]=0;
    }
}
main(){scanf("%d %d %d",&n,&x,&y);//1에서 5라면 1,2,3,4
    result[x-1] = result[y-1] = y-x-1;
    avail[y-x-1]=1;
    backtrack(0);
    printf("%lld",cnt);
}