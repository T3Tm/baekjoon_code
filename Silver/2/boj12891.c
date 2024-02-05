#include <string.h>
/*
 https://www.acmicpc.net/problem/12891
 12891번 DNA 비밀번호
*/
int s,p;
int a,c,g,t;//
int A,C,G,T;
char word[1000000];
long long cnt;
main(){scanf("%d %d",&s,&p);
    scanf("%s",word);
    scanf("%d %d %d %d",&a,&c,&g,&t);
    int len=strlen(word);
    int left=0,right=p;
    for(int i=0;i<p;i++){
        switch(word[i]){
            case 'A':
                A++;
                break;
            case 'C':
                C++;
                break;
            case 'G':
                G++;
                break;
            case 'T':
                T++;
                break;
        }
    }
    if(A>=a && C>=c && G>=g && T>=t)cnt++;
    while(right<len){
        switch(word[right++]){
            case 'A':
                A++;
                break;
            case 'C':
                C++;
                break;
            case 'G':
                G++;
                break;
            case 'T':
                T++;
                break;
        }
        switch(word[left++]){
            case 'A':
                A--;
                break;
            case 'C':
                C--;
                break;
            case 'G':
                G--;
                break;
            case 'T':
                T--;
                break;
        }
        if(A>=a && C>=c && G>=g && T>=t)cnt++;
    }
    printf("%lld",cnt);
}
