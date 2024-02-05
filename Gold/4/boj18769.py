'''
https://www.acmicpc.net/problem/18769
18769번 그리드 네트워크

쉬운 그래프 => 다익스트라 문제

좌측 상단부터 0,0으로 시작하겠음

0,0 <-> 1 <-> 0,1  <->  3 <-> 0,2
2 4 2
3   1


c*r+column


'''
import sys
readLine=sys.stdin.readline
def find(a):
    if parent[a]==a:return a
    parent[a]=find(parent[a])
    return parent[a]
def union(x,y):
    a,b=find(x),find(y)
    if a<b:parent[b]=a
    else:parent[a]=b
for _ in[0]*int(readLine()):
    r,c=map(int,readLine().split())
    parent=[i for i in range(r*c)]
    graph=[]
    for row in range(r):
        graphs = map(int,readLine().split())
        for column,cost in enumerate(graphs):
            graph.append((cost,c*row+column,c*row+column+1))
    for row in range(r-1):
        graphs = map(int,readLine().split())
        for column,cost in enumerate(graphs):
            graph.append((cost,c*row+column,c*row+column+c))
    total=cnt=0
    graph.sort()
    for idx,(cost,x,y) in enumerate(graph):
        if find(x)!=find(y):#그래프 적으로 연결 안 됐을 때
            union(x,y)
            total+=cost
            cnt+=1
        if cnt==r*c-1:break
    print(total)