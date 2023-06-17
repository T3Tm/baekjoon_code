#include <stdio.h>
/*
 https://www.acmicpc.net/problem/2891
 2891번 카약과 강풍
 양 옆에 적절히 빌려주면 된다.
 앞에서부터 옆에 없으면 빌려주면 되는데.
 앞에서부터 왼쪽 오른쪽 그냥 빌려주면 된다.
 그 다음 없는 팀 구해주면 된다.
 */
int n,s,r,t,cnt;
int ka[11];//10팀까지만 있음
int main() {
    scanf("%d %d %d",&n,&s,&r);
    for(int i=1;i<=n;i++)ka[i]=1;//모두 처음에는 1개씩 있는 것
    for(int i=1;i<=s;i++)scanf("%d",&t),ka[t]=0;//손상됨.
    for(int i=1;i<=r;i++)scanf("%d",&t),ka[t]++;//카약 여분소지.
    for(int i=1;i<=n;i++){
        if(i!=1 && ka[i-1]==0 && ka[i]>=2)ka[i-1]=1,ka[i]--;
        if(i!=n && ka[i+1]==0 && ka[i]>=2)ka[i+1]=1,ka[i]--;
    }
    for(int i=1;i<=n;i++)(!ka[i]?cnt++: cnt);
    printf("%d",cnt);
}