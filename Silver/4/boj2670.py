'''
https://www.acmicpc.net/problem/2670
2670번 연속부분최대곱
'''
n=int(input())
a=[float(input())for _ in[0]*n]
for i in range(1,n):a[i]=max(a[i-1]*a[i],a[i])
print(f'{max(a):.3f}')