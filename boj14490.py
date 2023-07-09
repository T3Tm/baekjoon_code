'''
https://www.acmicpc.net/problem/14490
14490번 백대열
'''
n,m=map(int,input().split(':'))
a,b={},{}
def prime(a:dict,n):
    start=2
    while start*start<=n and n!=1:
        if not n%start:a[start]=a.get(start,0)+1;n//=start
        else:start+=1
    if n!=1:a[n]=a.get(n,0)+1
prime(a,n)
prime(b,m)
A=B=1
for i in a:
    if i in b:#O(1)
        cnt=min(a[i],b[i])
        b[i]=max(b[i]-cnt,0)
        a[i]=max(a[i]-cnt,0)
    A*=i**a[i]
for i in b:
    B*=i**b[i]
print(f'{A}:{B}')