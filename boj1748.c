#include<stdio.h>
/*
 https://www.acmicpc.net/problem/1748
 1748번 수 이어 쓰기 1
 n이 1억까지 들어온다.
 
*/
typedef long long ll;
ll result;
ll number=1,start=1;
main(){
    int n;scanf("%d",&n);
    int temp=n,len=0;
    while(temp){
        temp/=10;len++;
    }
    while(number!=len){
        temp=start;
        start*=10;
        result+=(start-temp)*number;
        number++;
    }
    result+=number*(n-start+1);
    printf("%lld",result);//0은 없어야 되기 때문에
}