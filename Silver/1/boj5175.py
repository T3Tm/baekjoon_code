'''
https://www.acmicpc.net/problem/5175
5175번 문제없는 문제
'''
import sys
input = sys.stdin.readline
def back(depth, pick, pre):
    global flag, m,n,problem,res
    if flag:return
    if depth == len(pick):
        s = set()
        for i in pick:#뽑은 애들
            s |= problem[i]
        if len(s) != m:return
        flag = True
        for i in pick:
            res += f"{chr(i + 64)} "
        return
    for i in range(pre, n+1):
        pick[depth] = i
        back(depth + 1, pick, i+1)
for _ in range(1,int(input())+1):
    m,n = map(int,input().split())
    problem = {}
    flag = False
    res = f"Data Set {_}: "
    for i in range(1,n+1):
        problem[i] = set(map(int,input().split()))
    
    for count in range(1,n+1):#1개부터 n개까지 골라서 m개를 만듦
        pick = [0] * count
        back(0,pick,1)
        if flag:break
    
    print(res+"\n")
        