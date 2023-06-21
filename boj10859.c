#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*
 https://www.acmicpc.net/problem/10859
 10859번 뒤집어진 소수
 */
int trans[12]={0,1,2,-1,-1,5,9,-1,8,6};
long long n,a;
char result[5]="yes";
bool prime(long long n){
    if(n==1)return 0;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
main(){scanf("%lld",&n);
    if(prime(n)){
        while(n){
            if(n%10 == 3 || n%10 == 4 || n%10 ==7){
                strcpy(result,"no");break;
            }
            a=a*10+trans[n%10];
            n/=10;
        }
    }else strcpy(result,"no");
    if(result[0]!='n' && !prime(a))strcpy(result,"no");
    printf("%s",result);
}