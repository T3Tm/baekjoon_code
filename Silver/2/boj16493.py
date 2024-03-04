n,m=map(int,input().split())
can = []
for _ in[0]*m:
    a,b=map(int,input().split())
    can.append([a,b])
dp = [-1]*(n+1)
dp[0] = 0
for key,v in sorted(can,key=lambda x:(x[0],-x[1])):
    for i in range(n,key-1,-1):
        if dp[i-key]!=-1:
            dp[i] = max(dp[i-key] + v,dp[i])
print(max(dp))