'''
항이 n개 있으면
n/2개 구하고 n/2개 구해서
보내준다.
a+ar+ar^2+ar^3+ar^4
'''
a,r,n,MOD=map(int,input().split())
print(a*n%MOD if r==1 else a*(pow(r,n,MOD*(r-1))-1)//(r-1)%MOD)