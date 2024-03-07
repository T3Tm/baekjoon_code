'''
https://www.acmicpc.net/problem/1079
1079번 마피아
'''
import sys
input = sys.stdin.readline
DIE = -20000
res = 0
def back(ill,me,day,alive):#몇 번의 밤이 지나는지 확인
    global n,res
    if alive==1 or ill[me]==DIE:#나 혼자 남았으니 현재 day 기록
        res = max(res,day)
        return
    if alive&1:
        small=idx=DIE
        for i in range(n):
            if small<ill[i]:
                small=ill[i]
                idx=i
        temp = ill[idx]
        ill[idx]=DIE#죽이기
        back(ill,me,day,alive-1)
        ill[idx]=temp
    else:
        cache = ill[::]
        for i in range(n):
            if ill[i]!=DIE:#한 명만 죽이면 된다.
                for j in range(n):
                    if i==j or ill[j]==DIE:continue
                    ill[j] += board[i][j]
                ill[i] = DIE
                back(ill,me,day+1,alive-1)
                ill = cache[::]#원복
n=int(input())
ill=[*map(int,input().split())]
board=[[*map(int,input().split())]for _ in[0]*n]
me=int(input())
back(ill,me,0,n)
print(res)