'''
https://www.acmicpc.net/problem/2567
2567번 색종이 - 2
'''
board=[[0]*(105)for _ in[0]*(105)]
for _ in[0]*int(input()):
    a,b=map(int,input().split())
    for x in range(a,a+10):
        for y in range(b,b+10):
            board[x][y]=1
t=0
def fourMeeting(x: int,y: int) -> int:
    move = (0,1),(0,-1),(1,0),(-1,0)
    cnt = 0
    for dx,dy in move:
        nx,ny = x+dx,y+dy
        if nx < 0 or nx >100 or ny < 0 or ny>100 : continue
        if board[nx][ny] == 0:cnt+=1
    return cnt
for x in range(105):
    for y in range(105):
        if board[x][y]:
            t+=fourMeeting(x,y)
print(t)