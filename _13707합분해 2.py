import math
n,k = map(int,input().split())
print(math.comb(k+n-1,n)%1000000000)