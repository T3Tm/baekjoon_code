'''
https://www.acmicpc.net/problem/15720
15720번 카우버거

'''
INPUT=lambda:map(int,input().split())
b,c,d=INPUT()
bugur=sorted([*INPUT()])
side=sorted([*INPUT()])
drink=sorted([*INPUT()])
pre=after=0
idx=0
for i in range(min(b,c,d)):#제일 작은 아이로 세트의 갯수를 맞춰야 한다.
    i+=1
    pre+=bugur[-i]+side[-i]+drink[-i]
    after+=(bugur[-i]+side[-i]+drink[-i])*9//10
    idx=i-1
for inner in range(idx+1,b):
    pre+=bugur[-(inner+1)]
    after+=bugur[-(inner+1)]
for inner in range(idx+1,c):
    pre+=side[-(inner+1)]
    after+=side[-(inner+1)]
for inner in range(idx+1,d):
    pre+=drink[-(inner+1)]
    after+=drink[-(inner+1)]
print(f'{pre}\n{after}')