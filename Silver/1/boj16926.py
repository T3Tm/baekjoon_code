'''
https://www.acmicpc.net/problem/15903
15903번 카드 합체 놀이
'''
from heapq import*
n,m=map(int,input().split())
z=[*map(int,input().split())]
heapify(z)
for _ in[0]*m:
    a,b=heappop(z),heappop(z)
    heappush(z,a+b);heappush(z,a+b)
print(sum(z))