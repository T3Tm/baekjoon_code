import sys
sys.setrecursionlimit(10**9)
input=sys.stdin.readline
n,m=map(int,input().split())
board=[[*input().rstrip()]for _ in[0]*n]


MOVE=(0,1),(1,0),(-1,0),(0,-1)

plus={}
idx=1
visited=[[-1]*m for _ in[0]*n]
def dfs(x:int,y:int,cnt:int,depth:int=1)->int:
    visited[x][y]=cnt
    for dx,dy in MOVE:
        nx=x+dx
        ny=y+dy
        if nx<0 or nx>=n or ny<0 or ny>=m:continue
        if visited[nx][ny]!=-1 or board[nx][ny]=='1':continue
        depth=max(depth,dfs(nx,ny,cnt,depth+1))
    return depth
for i in range(n):
    for j in range(m):
        if visited[i][j]==-1 and board[i][j]=='0':
            value = dfs(i,j,idx)
            plus[idx]=value
            idx+=1

def zerocount(x:int,y:int,ret:int=0)->int:
    preplus=set()
    for dx,dy in MOVE:
        nx= x+dx
        ny= y+dy
        if nx<0 or nx>=n or ny<0 or ny>=m:continue
        if visited[nx][ny]==-1:continue#1이라는 의미임
        value = visited[nx][ny]
        if value in preplus:continue
        preplus.add(value)
        ret+=plus[value]
    return (ret+1)%10

for i in range(n):
    for j in range(m):
        if visited[i][j]==-1 and board[i][j]=='1':
            board[i][j]=zerocount(i,j)

for row in board:
    for value in row:
        print(value,end='')
    print()