from collections import deque
import sys
readLine=sys.stdin.readline
r,c=map(int,readLine().split())
fire=deque()
J=deque()
graph=[]
Move=(0,1),(0,-1),(1,0),(-1,0)
fire_visit=[[-1]*c for _ in[0]*r]
J_visit=[[-1]*c for _ in[0]*r]

for row in range(r):
    temp=readLine().rstrip()
    for column,value in enumerate(temp):
        if value == 'J':
            J.append([row,column])
            J_visit[row][column]=0
        elif value == 'F':
            fire.append([row,column])
            fire_visit[row][column]=0
    graph.append(temp)
while fire:
    x,y=fire.popleft()
    for dx,dy in Move:
        nx,ny=x+dx,y+dy
        if nx<0 or nx>=r or ny<0 or ny>=c:continue
        if fire_visit[nx][ny]>=0 or graph[nx][ny]=='#':continue
        fire_visit[nx][ny]=fire_visit[x][y]+1
        fire.append([nx,ny])
while J:
    x,y=J.popleft()
    for dx,dy in Move:
        nx,ny=x+dx,y+dy
        if nx<0 or nx>=r or ny<0 or ny>=c:
            print(J_visit[x][y]+1)
            exit()
        if J_visit[nx][ny]>=0 or graph[nx][ny]=='#' or graph[nx][ny]=='F':continue
        if J_visit[x][y]+1 < fire_visit[nx][ny] or fire_visit[nx][ny]==-1:
            J_visit[nx][ny]=J_visit[x][y]+1
            J.append([nx,ny])
print('IMPOSSIBLE')