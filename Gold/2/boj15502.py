import sys
sys.setrecursionlimit(100000)
def find(a):
    if parent[a] == -1: return a
    parent[a] = find(parent[a])
    return parent[a]
def merge(a,b):
    A = find(a)
    B = find(b)
    if A>B:parent[A] = B
    elif A < B:parent[B] = A
MOD = int(1e9) + 7
input = sys.stdin.readline
n,m = map(int,input().split())
parent = [-1]*(n+1)
for _ in[0]*m:
    l,r,k = map(int,input().split())
    plus = l
    while plus + k <= r:
        merge(plus,plus+k)
        plus+=1
print(pow(2,len([*filter(lambda x:x == -1,parent)])-1,MOD))