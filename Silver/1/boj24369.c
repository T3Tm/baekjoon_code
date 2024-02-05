#include <stdio.h>
#define max(a,b) (a>b?a:b)
/*
 https://www.acmicpc.net/problem/24369
 24369번 알고리즘 수업 - 점근적 표기 5
 ax^2+ax+a>=c*x^2
 
 */
int a,b,c,d,e;
main() {
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    double value;
    if(a==d)value=e;
    else value=max((double)b/(-2*(a-d)),e);
    if((a-d)*(value)*value+b*value+c>=0 && a-d>=0) printf("1");
    else printf("0");
}
