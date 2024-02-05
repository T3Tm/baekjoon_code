'''
0 : 왼쪽으로 가는 중
1 : 오른쪽으로 가는 중
2 : 위로 가는 중
3 : 아래로 가는 중
'''
def trans(x,y,tile,see):# 다음 nx,ny를 리턴해준다.
    loc=-1,-1,-1
    move=(0,1),(0,-1),(1,0),(-1,0)
    if not tile:
        if not see:#왼쪽으로 가는 중
            loc= x+move[2][0],y+move[2][1],3
        elif see==2:
            loc= x+move[0][0],y+move[0][1],1
    elif tile==1:
        if see==1:#왼쪽으로 가는 중
            loc= x+move[2][0],y+move[2][1],3
        elif see==2:
            loc= x+move[1][0],y+move[1][1],0
    elif tile==2:
        if see==3:#왼쪽으로 가는 중
            loc= x+move[0][0],y+move[0][1],1
        elif not see:
            loc= x+move[3][0],y+move[3][1],2
    elif tile==3:
        if see==1:#왼쪽으로 가는 중
            loc= x+move[3][0],y+move[3][1],2
        elif see==3:
            loc= x+move[1][0],y+move[1][1],0
    elif tile==4:
        if see==3:#왼쪽으로 가는 중
            loc= x+move[2][0],y+move[2][1],3
        elif see==2:
            loc= x+move[3][0],y+move[3][1],2
    else:
        if see==1:#왼쪽으로 가는 중
            loc= x+move[0][0],y+move[0][1],1
        elif not see:
            loc= x+move[1][0],y+move[1][1],0
    return loc
def bfs():
    global result
    x,y,see=0,0,1
    time=0
    while 1:
        x,y,see=trans(x,y,board[x][y],see)
        time+=1
        if x==n-1 and y==n:
            result=min(result,time)
            return
        if(x,y,see) == (-1,-1,-1):break
        if x==n-1 and y==n:pass
        elif x<0 or x>=n or y<0 or y>=n:break
def solve():
    global n,k,board,result
    result=n*n+1
    if k:
        for i in range(n):
            for j in range(n):
                for z in range(6):
                    if board[i][j]==z:continue
                    re,board[i][j]=board[i][j],z
                    bfs()
                    board[i][j]=re
    else:bfs()
    print([result,-1][result==n*n+1])
n,k=map(int,input().split())
board=[[*map(int,input().split())]+[0]for _ in[0]*n]+[0]*(n+1)
solve()