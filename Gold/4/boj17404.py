import sys
sys.setrecursionlimit(1002)
input = sys.stdin.readline
INF = sys.maxsize
def rgb(depth, pre, start):
    if depth ==1:#마지막이라면 처음 그리고 pre과 다른 것을 보내주면 된다.
        ret = INF
        for i in range(3):
            if pre == i or start == i:continue
            ret = min(ret, board[depth][i])
        return ret
    if cache[depth][pre][start]!=INF:return cache[depth][pre][start]
    for i in range(3):
        if i==pre:continue
        cache[depth][pre][start] = min(cache[depth][pre][start],rgb(depth-1,i,start)+board[depth][i])
    return cache[depth][pre][start]
n=int(input())
board= [[0]*3] + [[*map(int,input().split())]for _ in[0]*n]
cache = [[[INF]*3 for _ in[0]*3]for _ in[0]*(n+1)]
ans = INF
for i in range(3):
    ans=min(ans,rgb(n-1,i,i)+board[n][i])
print(ans)