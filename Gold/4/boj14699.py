'''
높이는 서로 다르다. 

'''
from collections import deque
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
arr=[0]+[*map(int,input().split())]
dp=[0]*(n+1)#각 노드 지점의 최대값 
graph={}
connect=[0]*(n+1)
for _ in[0]*m:
    a,b=map(int,input().split())
    if arr[b]>arr[a]:#b가 더 크다면 a는 에다가 연결된 갯수 늘리기
        connect[a]+=1
        graph[b]=graph.get(b,[])
        graph[b].append(a)
    else:
        connect[b]+=1
        graph[a]=graph.get(a,[])
        graph[a].append(b)
queue=deque()
for idx,i in enumerate(connect[1:],1):
    if i==0:queue.append(idx)

while queue:
    cur = queue.popleft()
    for next in graph.get(cur,[]):
        connect[next]-=1
        if connect[next]==0:
            queue.append(next)
            dp[next]=max(dp[next],dp[cur]+1)
for i in dp[1:]:print(i+1)