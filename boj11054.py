i=input;m=max;i()
b=[0]*1001
a=b[:]
for _ in i().split():c=int(_);a[c]=m(a[:c])+1;b[c]=m(b[c+1:]+a[:c])+1
print(m(b))