'''
https://www.acmicpc.net/problem/21555
21555번 빛의 돌 옮기기
'''
f=lambda:map(int,input().split())
n,k=f()
a,b=[0]+[*f()],[0]+[*f()]
dp=[[0]*(2*int(1e5)+3)for _ in[0]*2]
for i in range(1,n+1):
    dp[0][i]=min(dp[0][i-1],dp[1][i-1]+k)+a[i]
    dp[1][i]=min(dp[0][i-1]+k,dp[1][i-1])+b[i]
print(min(dp[0][n],dp[1][n]))