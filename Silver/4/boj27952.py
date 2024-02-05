'''
하루에도 몇 번이라도 루틴을 진행해서 x만큼 weight를 줄일 수 있다.
n일에 걸친 식단을 짯음.
i일에 b[i]만큼 무조건 찜
'''
n,x=map(int,input().split())
A=[0]+[*map(int,input().split())]#이것보다 커야 됨.
B=[0]+[*map(int,input().split())]#이것만큼 찌게 됨.
weight=answer=0
for i in range(1,n+1):
    B[i]+=B[i-1]
    if B[i]<A[i]:
        answer=-1
        break
weight=B[-1]
print([(weight-A[-1])//x,-1][answer==-1])