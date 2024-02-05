'''
https://www.acmicpc.net/problem/21921
21921번 블로그
'''
n,m=map(int,input().split())
arr=[*map(int,input().split())]
cnt,tmp=1,0
for i in range(m):tmp+=arr[i]
answer=tmp
left=0
for right in range(m,n):
    tmp+=arr[right]
    tmp-=arr[left]
    left+=1
    if answer==tmp:cnt+=1
    elif answer<tmp:cnt=1
    answer=max(answer,tmp)
print("SAD"if answer==0 else answer)
if answer!=0:print(cnt)