n=int(input())+1
dp = [0]*30
dp[1] = 1
dp[4] = -1
for i in range(2,n):
    d = dp[i-1]
    dp[i] = d*2 + dp[i]
    dp[i + (3 if i&1 else 4)] -= d
print(*dp[1:21])