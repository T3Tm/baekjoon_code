'''
https://www.acmicpc.net/problem/1015
1015번 수열 정렬
B[P[i]]=A[i]
P[0],P[1],P[2]
1,2,3
2,0,1
B[0]=1
P[0](idx)=insertnum
B[1]=2
B[2]=3
'''
input();A=[*map(int,input().split())]
C=sorted([A[i],i] for i in range(len(A)))
P=[0]*(len(A))
for idx,value in enumerate(C):
    P[value[1]]=idx
print(*P)