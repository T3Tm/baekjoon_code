# M=100999
# dp=[[0]*1002 for _ in[0]*2003]
# result=[0]*2003
# for i in range(1,2001):
#     j=0
#     while i-j>j:
#         dp[i][j]+=1
#         z=j+1
#         while dp[i-j][z]!=0:
#             dp[i][j]=dp[i][j]+dp[i-j][z]
#             z+=1 
#         j+=1
# for i in range(1,2001):
#     j=0
#     while dp[i][j]!=0:
#         result[i]=(result[i]+dp[i][j])%M
#         j+=1
# t=int(input())
# for _ in[0]*t:
#     n=int(input())
#     print(result[n])
'''
2000~i
j-i =>
i : 1
j : 1999,1998~
i : 2
j : 1998,1997,
i : 3

i : 2000
j : 0
'''
M=2001
A=[1]+[0]*M
for i in range(1,M):#2000~1까지  
  for j in range(M-1,i-1,-1):A[j]=(A[j]+A[j-i])%100999
a,*b=map(int,open(0))
for _ in b:print(A[_])