'''
https://www.acmicpc.net/problem/23253
23253번 자료구조는 정말 최고야
'''
import sys
input=sys.stdin.readline
n,m=map(int,input().split())
connect=[0]*(n+1)
for _ in[0]*m:
    num=int(input())
    idx=-1
    for value in [*map(int,input().split())][::-1]:#이 다음에 연결된 아이가 가도 되는지 확인
        connect[value]=idx#이전 값 갖고 오기
        idx=value
fail=False
for i in range(1,n+1):
    if connect[i]==-1 or f'{connect[connect[i]]}'=='True':
        connect[i]=True
    else:fail=True;break
if fail:print('No')
else:print("Yes")