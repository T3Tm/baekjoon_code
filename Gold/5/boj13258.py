'''
https://www.acmicpc.net/problem/13258
13258번 복권 + 은행

2,(갯수)
1
1,2,1
1,3,3,1
1,4,6,4,1
1,5,10,10,5,1
1,6,15,20,15,6,1
1,7,21,35,35,21,7,1
'''
f=lambda:int(input())
n=f()
a,*_=map(int,input().split())
j=f()
c=f()
print(a+(a*j*c)/(sum(_)+a))