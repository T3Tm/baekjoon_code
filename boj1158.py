n,k=map(int,input().split())
t,result=[*range(1,n+1)],[]
visited=[0]*(n+1)
idx=cnt=0
if k!=1:
    while t:
        cnt+=1
        if cnt == k:
            cnt=1
            result.append(t[idx])
            t.pop(idx)
            if not t:break
        idx=(idx+1)%len(t)
else:result=t[:]
print('<',end='')
print(*result,sep=', ',end='')
print('>')