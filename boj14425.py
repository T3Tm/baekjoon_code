n,*a=open(0)
n,m=map(int,n.split())
b=a[:n]
print(sum(i in b for i in a[n:]))