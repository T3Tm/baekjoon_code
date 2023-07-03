'''
https://www.acmicpc.net/problem/24445
24445번 알고리즘 수업 - 너비 우선 탐색 2
'''
from collections import deque
import sys
input=sys.stdin.readline
n,m,r=map(int,input().split())
graph={}
for _ in[0]*m:
    u,v=map(int,input().split())
    graph[u]=graph.get(u,[])
    graph[u].append(v)
    graph[v]=graph.get(v,[])
    graph[v].append(u)
for i in range(1,n+1):graph.get(i,[]).sort(key=lambda x:-x)
cnt=2
V=[0]*(n+1)
q=deque([r])
V[r]=1
while q:
    cur = q.popleft()
    for next in graph[cur]:
        if V[next]:continue
        V[next]=cnt
        cnt+=1
        q.append(next)
print(*V[1:],sep='\n')