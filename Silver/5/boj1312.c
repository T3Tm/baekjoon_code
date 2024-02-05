#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/1312
 1312번 소수
*/
int a,b,n;
main(){
    scanf("%d %d %d",&a,&b,&n);
    if(n==1)a%=b;
    while(n!=1){
        a*=10;
        a%=b;
        n--;
    }
    printf("%d",a*10/b);
}
