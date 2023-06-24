#include <stdio.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/1074
 1074번 Z
 왼쪽 위 , 오른쪽 위
 왼쪽 아래, 오른쪽 아래
 
 중간을 갖고 있어야 한다.
*/
typedef long long ll;
int n,r,c;
ll longpow(int n){
    if(n==1)return 2;
    if(n%2==0){//짝수이므로
        return longpow(n/2)*longpow(n/2);
    }else{
        return longpow(n/2)*longpow(n/2)*2;
    }
}
ll T;
void Z(ll count,int x,int y,int width){//count 와 좌표
    if(width==1){
        printf("%lld",count);
        exit(0);
    }
    int minus=width/2/2;
    int plus=width/2;plus*=plus;
    if(r<x && c<y){//2사분면
        Z(count,x-minus,y-minus,width/2);
    }else if(r<x && c<y+width/2){//1사분면
        Z(count+plus,x-minus,y+minus,width/2);
    }else if(r<x+width/2 && c<y){//3사분면
        Z(count+plus*2,x+minus,y-minus,width/2);
    }else{//4사분면
        Z(count+plus*3,x+minus,y+minus,width/2);
    }
}
main(){
    scanf("%d %d %d",&n,&r,&c);
    T=longpow(n);
    Z(0,T/2,T/2,T);
}
