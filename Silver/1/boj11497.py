'''
https://www.acmicpc.net/problem/11497
11497번 통나무 건너뛰기
'''
import sys
from collections import deque
input=sys.stdin.readline
for _ in[0]*int(input()):
    input()
    arr=sorted(map(int,input().split()),reverse=True)
    n=deque([arr[0]])
    for i in range(1,len(arr)):
        if i%2==1:n.append(arr[i])
        else:n.appendleft(arr[i])
    answer=0
    for i in range(1,len(arr)):
        answer=max(answer,abs(n[i]-n[i-1]))
    print(answer)