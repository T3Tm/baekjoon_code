'''
https://www.acmicpc.net/problem/17952
17952번 과제는 끝나지 않아!

분단위로 과제가 추가된다.
1. 과제는 가장 최근에 나온 순서대로 진행. (과제가 나오면 바로 진행)
2. 과제를 하다가 새로운 과제가 나오면, 과제를 중단하고 새로운 과제 진행(선점 스케줄링..?)
3. 새로운 과제가 끝나면, 이전에 과제를 진행

스케줄링 문제네.
스케줄링은 heap을 이용해서 풀면 된다.

'''
import sys
input=sys.stdin.readline
n=int(input())
q=[]
answer=0
for i in[0]*n:
    a,*b=map(int,input().split())
    if a:q.append([b[0],b[1]])
    if q:#값이 있을 때만 진행
        if q[-1][1]-1==0:
            answer+=q.pop()[0]  
        else:
            q[-1][1]-=1
print(answer)