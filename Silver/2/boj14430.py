import sys
input = sys.stdin.readline 
n,m=map(int,input().split())
board=[[*map(int,input().split())]for _ in[0]*n]
dp=[[-1]*m for _ in[0]*n]
def dfs(x,y):
    if x==n-1 and y==m-1:return board[x][y]
    if dp[x][y]!=-1:return dp[x][y]
    dp[x][y]=0
    for dx,dy in (0,1),(1,0):
        nx,ny=x+dx,y+dy
        if nx<0 or nx>=n or ny<0 or ny>=m:continue
        dp[x][y]=max(dfs(nx,ny)+board[x][y],dp[x][y])
    return dp[x][y]
print(dfs(0,0))