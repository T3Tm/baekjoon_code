import sys
input = sys.stdin.readline
n = int(input())
arr = [[0]*3]+[[*map(int,input().split())]for _ in[0]*n]
dp=[0]*(n+1)
for i in range(1,n+1):
    dp[i] = max(dp[i-1], dp[i-2] + arr[i][2])
print(max(dp))