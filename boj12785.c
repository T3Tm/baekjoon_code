#include <stdio.h>
/*
 https://www.acmicpc.net/problem/12785
 12785번 토쟁이의 등굣길
 ((x-1)+(y-1))!/((x-1)!*(y-1)!)*((w-x)+(h-y))!/((w-x)!*(h-y)!)
 */
int w,h,x,y;
const int MOD=1e6+7;
int dp[202][202];
main() {scanf("%d %d %d %d",&w,&h,&x,&y);
    dp[1][1]=dp[1][0]=dp[0][1]=1;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(i==1)dp[i][j]=dp[i][j]=dp[i][j-1]%MOD;
            else if(j==1)dp[i][j]=dp[i-1][j]%MOD;
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    for(int i=x;i<=w;i++){
        for(int j=y;j<=h;j++){
            if(i==1)dp[i][j]=dp[i][j]=dp[i][j-1]%MOD;
            else if(j==1)dp[i][j]=dp[i-1][j]%MOD;
            else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
        }
    }
    printf("%d",dp[w][h]);
}