'''
https://www.acmicpc.net/problem/6064
6064번 카잉 달력
3, 9
1,1
2,2
3,3
4,4
5,5
6,6
7,7
8,8
9,9
10,10
1,11
2,12
3,1
4,2
5,3
6,4
7,5
8,6
9,7
10,8
1,9
2,10
3,11
4,12
5,1
6,2
7,3
8,4
9,5
10,6
1,7
2,8
3,9
3,7 
3,
'''
import sys
input=sys.stdin.readline

for _ in[0]*int(input()):#T
    m,n,x,y=map(int,input().split())
    mset=[0]*(n+1)
    X,Y,year=x,n if x%n==0 else x%n,x

    while (X,Y)!=(x,y):
        if mset[Y]:
            year=-1
            break
        mset[Y]=1
        Y=n if (Y+m)%n==0 else(Y+m)%n
        year+=m
    print(year)