import sys
sys.setrecursionlimit(10**7)
def dfs(num,idx,insertnum):
    global remember,m
    m[idx]=insertnum
    if idx==len(m)-1:
        print(*m[1:])
        exit(0)
    if num==m[idx+1]:dfs(num,idx+1,insertnum+1)
    elif num+1 == m[idx+1]:
        remember[num]=insertnum+1
        dfs(num+1,idx+1,1)
    elif num>m[idx+1]:
        insertnum=remember.get(m[idx+1],-1)
        if insertnum==-1:
            print(-1)
            exit(0)
        dfs(m[idx+1],idx+1,insertnum)
    else:#이상한 수
        print(-1)
        exit(0)
c=int(input())
m=[0]+[*map(int,input().split())]
remember={}
dfs(0,0,1)