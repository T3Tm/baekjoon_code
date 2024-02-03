# l,r=map(lambda x:f'{int(x):010}',input().split())
# a=b=0
# while a<len(l)and l[a]==r[a]:a+=1;b+=l[a]=='8'
# print(b)
# 88x8xx
# 88x8xx
# 885800 889899
c=0
l,r=map(int,input().split())
while l:
 if r==l and l%10==8:c+=1
 l//=10;r//=10
print(c)