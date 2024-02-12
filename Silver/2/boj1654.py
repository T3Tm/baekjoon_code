import sys
input = sys.stdin.readline
k,l = map(int,input().split())
arr = [int(input())for _ in[0]*k]
left = 1;right = 2**32 - 1
while left<=right:
    mid = (left+right)//2
    cnt = 0
    for i in arr:
        cnt += i//mid
    if cnt < l:
        right = mid - 1
    else:
        left = mid +1
print(right)