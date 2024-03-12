import sys
input = sys.stdin.readline
idx = 1
INF = sys.maxsize
def f(x,y):
    if x==n-1 and y==1:return board[x][y]
    if dp[x][y]!=INF:return dp[x][y]
    for dx,dy in (0,1),(1,0),(1,1),(1,-1):
        nx,ny = x+dx,y+dy
        if nx<0 or nx>=n or ny<0 or ny>=3:continue
        dp[x][y] = min(dp[x][y],f(nx,ny)+board[x][y])
    return dp[x][y]
while n:=int(input()):
    board = [[*map(int,input().split())]for _ in[0]*n]
    dp = [[INF]*3 for _ in[0]*n]
    print(f'{idx}. {f(0,1)}')
    idx+=1