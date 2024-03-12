import sys
input = sys.stdin.readline
n = int(input())
board = [[*map(int,input().split())]for _ in[0]*n]
dp = [[-1]*n for _ in[0]*n]
def f(x,y):
    if x==n-1 and y==n-1:
        return 1
    if dp[x][y]!=-1:return dp[x][y]
    dp[x][y] = 0
    for dx,dy in (0,1),(1,0):
        nx,ny = x+dx*board[x][y],y+dy*board[x][y]
        if nx < 0 or nx >=n or ny<0 or ny>=n:continue
        dp[x][y] += f(nx,ny)
    return dp[x][y]
print(f(0,0))