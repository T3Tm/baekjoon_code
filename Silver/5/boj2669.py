'''
https://www.acmicpc.net/problem/2669
2669번 직사각형 네개의 합집합의 면적 구하기
'''
board=[[0]*102 for _ in[0]*102]
for i in[0]*4:
    a,b,c,d=map(int,input().split())
    for j in range(a,c):
        for z in range(b,d):board[j][z]=1
cnt=0
for i in range(1,101):
    for j in range(1,101):
        cnt=cnt+1 if board[i][j]else cnt
print(cnt)