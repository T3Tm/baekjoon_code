'''
https://www.acmicpc.net/problem/1120
1120번 문자열
'''
a,b=input().split()
if len(a)>len(b):b,a=a,b
cnt=51
for i in range(0,len(b)-len(a)+1):
    tmp=0
    for j in range(len(a)):
        if a[j]==b[j+i]:tmp+=1
    cnt=min(len(a)-tmp,cnt)
print(cnt)