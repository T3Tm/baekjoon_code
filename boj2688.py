dp=[[0]*10 for _ in[0]*66]
for z in range(10):dp[1][z]=1
for i in range(2,65):
    for z in range(0,10):
        for j in range(0,z+1):
            dp[i][z]+=dp[i-1][j]
for _ in[0]*int(input()):
    print(sum(dp[int(input())]))