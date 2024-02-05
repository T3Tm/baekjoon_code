n,*l=open(0)
d={};n,m=map(int,n.split())
for i in l[:n]:
    a,b=i.split()
    d[a]=b
for j in l[n:]:print(d[j.strip()])