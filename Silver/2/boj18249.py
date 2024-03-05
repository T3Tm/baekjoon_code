import sys
input = sys.stdin.readline
dp=[1]*191230
for i in range(2,191230):
    dp[i] = dp[i-1]+dp[i-2]
for _ in[0]*int(input()):
    print(dp[int(input())])