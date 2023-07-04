/*
 https://www.acmicpc.net/problem/10844
 10844번 쉬운 계단 수
*/
int n;
int dp[102][11];
const int MOD = 1e9;
main(){scanf("%d",&n);
    for(int i=2;i<=10;i++)dp[1][i]=1;
    for(int i=2;i<=n;i++)for(int j=1;j<=10;j++)dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%MOD;
    int result=0;
    for(int i=1;i<=10;i++)result=(result+dp[n][i])%MOD;
    printf("%d",result);
}
