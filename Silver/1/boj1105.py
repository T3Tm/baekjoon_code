l,r=map(lambda x:f'{int(x):010}',input().split())
a=b=0
while a<len(l)and l[a]==r[a]:a+=1;b+=l[a]=='8'
print(b)