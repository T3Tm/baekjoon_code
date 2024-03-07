import sys
input = sys.stdin.readline
n = int(input())
dp=[0]*(n+1)
arr=[0]+[int(input())for _ in[0]*n]
for i in range(1,n+1):
    maxi=0
    for j in range(i):
        if arr[j]<arr[i]:
            maxi=max(maxi,dp[j])
    dp[i]=maxi+arr[i]
print(max(dp))