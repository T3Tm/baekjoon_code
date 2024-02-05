'''
https://www.acmicpc.net/problem/14916
14916번 거스름돈
'''
n=int(input())
dp=[-1]*100002
dp[0]=0
for i in range(2,n+1):
    if dp[i-2]!=-1:dp[i]=dp[i-2]+1
for i in range(5,n+1):
    if dp[i-5]!=-1:dp[i]=dp[i-5]+1
print(dp[n])