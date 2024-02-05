import math
f=lambda:map(int,input().split())
b=math.factorial
w,h=f()
x,y=f()
print((b(((x-1)+y-1))//(b(x-1)*b(y-1))*b(w-x+h-y)//(b(w-x)*b(h-y)))%1000007)