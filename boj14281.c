#include <stdio.h>
/*
 https://www.acmicpc.net/problem/14281
 14281번 볼록 수열
 1<=x<=n-2
 해당 구간에서

 */
int a[53],n,V,L=1,i;
long long C;
int main(){
    scanf("%d",&n);
    for(;i<n;i++)scanf("%d",&a[i]);
    for(;L;){L=0;
        for(i=1;i<=n-2;i++){//
            if (a[i-1]+a[i+1]<a[i]*2)V=(a[i-1]+a[i+1])/2,C+=a[i]-V,a[i]=V,L++;
        }
    }
    printf("%ld",C);
}