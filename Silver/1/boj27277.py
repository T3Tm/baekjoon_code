'''
https://www.acmicpc.net/problem/27277
27277번 장기자랑
1,3,10,15,9,8

9,8,3,10,1,15

9 + 7 + 14
'''
from math import ceil
answer=0
n=int(input())
arr=sorted(map(int,input().split()))
idx=-1
for i in range(ceil(n/2)-1):
    answer+=arr[-(i+1)]-arr[i]
    idx=i
answer+=arr[-(idx+2)]
print(answer)