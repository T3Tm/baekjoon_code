import sys
input=sys.stdin.readline
n,m=map(int,input().split())
graph={}
for _ in[0]*m:
    a,b=map(int,input().split())
    graph[a]=graph.get(a,[])
    graph[a].append(b)
    graph[b]=graph.get(b,[])
    graph[b].append(a)
for i in range(1,n+1):
    print(len(graph.get(i,[])))