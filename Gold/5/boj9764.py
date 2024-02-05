M=100999
dp=[[0]*1002 for _ in[0]*2003]
result=[0]*2003
for i in range(1,2001):
    j=0
    while i-j>j:
        dp[i][j]+=1
        z=j+1
        while dp[i-j][z]!=0:
            dp[i][j]=dp[i][j]+dp[i-j][z]
            z+=1 
        j+=1
for i in range(1,2001):
    j=0
    while dp[i][j]!=0:
        result[i]=(result[i]+dp[i][j])%M
        j+=1
t=int(input())
for _ in[0]*t:
    n=int(input())
    print(result[n])