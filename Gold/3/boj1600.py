'''
https://www.acmicpc.net/problem/1600
1600번 말이 되고픈 원숭이
'''
import sys
from collections import deque
input = sys.stdin.readline
k = int(input())
m,n = map(int,input().split())
board = [[*map(int,input().split())]for _ in[0]*n]
visited = [[[-1]*(m+1)for _ in[0]*n]for _ in[0]*(k+1)]
visited[0][0][0] = 0
q = deque([[0,0,0]])#0,0 좌표에서 k 번 뛴 거
MOVE = (-2,1) , (-1,2),(1,2) , (2,1) , (2,-1), (1,-2), (-1,-2),(-2,-1)
move = (0,1), (0,-1), (1,0),(-1,0)
res = sys.maxsize
while q:
    x,y,nowk = q.popleft()
    if x == n -1 and y == m-1:
        res = visited[nowk][x][y]
        break
    next = move
    if nowk+1<=k: next += MOVE
    for idx, (dx,dy) in enumerate(next):
        nx,ny = x+dx,y+dy
        if nx < 0 or nx>=n or ny<0 or ny>=m:continue
        if board[nx][ny] == 1:continue
        if visited[nowk+(idx>3)][nx][ny] != -1:continue
        visited[nowk+(idx>3)][nx][ny] = visited[nowk][x][y] + 1
        q.append([nx,ny,nowk+(idx>3)])
print([res,-1][res == sys.maxsize])