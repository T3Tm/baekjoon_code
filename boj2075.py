'''
https://www.acmicpc.net/problem/2075
2075번 N번째 큰 수
해당 문제는 힙을 이용하는 문제
'''
from heapq import*
h=[]
n=int(input())
for i in[0]*n:
    for j in map(int,input().split()):heappush(h,j);heappop(h) if len(h)>n else j
print(h[0])