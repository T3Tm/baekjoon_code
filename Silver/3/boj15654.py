'''
https://www.acmicpc.net/problem/15654
15654번 N과 M (5)

'''
def NandM(depth,result,avail):
    global n,m,r
    if depth==m:
        print(*result)
        return
    for i in range(n):
        if not avail[i]:
            avail[i]=1
            result[depth]=r[i]
            NandM(depth+1,result,avail)
            result[depth]=0
            avail[i]=0
n,m=map(int,input().split())
r=sorted(map(int,input().split()))
NandM(0,[0]*m,[0]*n)