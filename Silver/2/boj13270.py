n=int(input())+1
arr=[0]+[*map(int,input().split())]
dp=[0]*n
for i in range(1,n):
    a = -1
    for j in range(i):
        if arr[j]<arr[i]:a=max(a,dp[j])
    dp[i] = a + 1
print(max(dp))