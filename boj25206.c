#include <stdio.h>
#include <string.h>
/*
 https://www.acmicpc.net/problem/25206
 25206번 너의 평점은
*/
char a[52],c[3];
double b;
double total,total_;
main(){
    for(int i=0;i<20;i++){
        scanf("%s %lf %s",a,&b,c);
        if(!strcmp(c,"A+"))total+=4.5*b;
        else if(!strcmp(c,"A0"))total+=4.0*b;
        else if(!strcmp(c,"B+"))total+=3.5*b;
        else if(!strcmp(c,"B0"))total+=3.0*b;
        else if(!strcmp(c,"C+"))total+=2.5*b;
        else if(!strcmp(c,"C0"))total+=2.0*b;
        else if(!strcmp(c,"D+"))total+=1.5*b;
        else if(!strcmp(c,"D0"))total+=b;
        
        if(strcmp(c,"P"))total_+=b;
    }
    printf("%lf",total/total_);
}