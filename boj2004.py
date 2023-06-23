'''
2,000,000,000 
0<=x<=20억
nCm
'''
from math import comb 
n,m=map(int,input().split())
b=comb(n,m)
cnt=0
while b%10==0:cnt+=1;b//=10
print(cnt)