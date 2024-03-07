n,k=map(int,input().split())
arr=[0]+[*map(int,input().split())]
dp=[[0,1]for _ in[0]*(n+1)]#0번은 1번 점프 쓴 곳, 1은 안 쓴곳
ans = 0
for i in range(2,n+1):
    dp[i][0] = dp[i-1][0]
    if arr[i-1]<=k:dp[i][1]=dp[i-1][1]+1
    else:
        ans=max(ans,dp[i][0]+dp[i-1][1])
        dp[i][0]=dp[i-1][1]
ans = max(ans,dp[n][0]+dp[n][1])
print(ans)