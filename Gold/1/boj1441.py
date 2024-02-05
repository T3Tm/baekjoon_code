import math
from itertools import combinations 
n,l,r=map(int,input().split())
arr=[*map(int,input().split())]
count = 0
lcm = math.lcm
for i in range(1,n+1):
    for comb in combinations(arr,i):
        num = lcm(*comb)
        startCnt = l // num
        endCnt = r // num
        if i % 2:count += endCnt - startCnt + +(not (l % num))
        else:count -= endCnt - startCnt + +(not (l % num))
print(count)