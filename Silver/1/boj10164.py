'''
https://www.acmicpc.net/problem/10164
10164번 격자상의 경로

k의 행값과 열 값을 알고 싶다.

'''
from math import factorial as f
def t(n,m):return f(n+m)//(f(n)*f(m))
n,m,k=map(int,input().split())
n,m=n-1,m-1
if k:#행,열
    f1,f2=(k-1)//(m+1),k-1-(k-1)//(m+1)*(m+1)
    print(t(f1,f2)*t(n-f1,m-f2))
else:
    print(t(n,m))