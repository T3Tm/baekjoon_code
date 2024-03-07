'''
https://www.acmicpc.net/problem/6135
6135번 Cow Hurdles
'''
import sys
input = sys.stdin.readline
INF = sys.maxsize
n,m,t = map(int,input().split())
visited= [[INF]*(n+1) for _ in[0]*(n+1)]
for i in[0]*m:
    a,b,v = map(int,input().split())
    visited[a][b]=min(visited[a][b],v)
for k in range(1,n+1):
    for s in range(1,n+1):
        for e in range(1,n+1):
            visited[s][e] = min(visited[s][e], max(visited[s][k],visited[k][e]))
for _ in[0]*t:
    a,b=map(int,input().split())
    print([visited[a][b],-1][visited[a][b]==INF])