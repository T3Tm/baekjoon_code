d=[0]*4
_,*b=open(0)
for i in b[0].split():
  i=int(i)
  if d[0]<i:d[0]=i
  elif d[1]<i:d[1]=i
  elif d[2]<i:d[2]=i
  elif d[3]<i:d[3]=i
  else:print("NO");break
else:print("YES")