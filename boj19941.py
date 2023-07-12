'''
https://www.acmicpc.net/problem/19941
19941번 햄버거 분배
'''
n,k=map(int,input().split())
hamber=input()
visited=[0]*(n+1)
cnt=0
for idx,key in enumerate(hamber):
    if key=='P':#사람일 때 앞에 햄버거 있는 거 하나씩 주면 됨.
        for i in range(max(idx-k,0),min(idx+k+1,len(hamber))):
            if not visited[i] and hamber[i]=='H':
                visited[i]=1
                cnt+=1
                break
print(cnt)