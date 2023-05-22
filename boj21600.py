'''
https://www.acmicpc.net/problem/21600
21600번 계단
'''

#코드
n=int(input())
stair=result=0
for i in map(int,input().split()):
    if stair<i:stair+=1
    else:stair=min(stair,i)
    result=max(result,stair)
print(result)

#숏코딩
s=r=0
_,*a=open(0)
for i in a[0].split():i=int(i);s=s+1 if s<i else min(s,i);r=max(r,s)
print(r)
