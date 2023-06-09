'''
https://www.acmicpc.net/problem/10892
10892번 Divide into triangle    

입력 받은 것들을 적절히 잘 분배하면 되는데.
내가 봤을 때
구역을 나누는 것을 어떤식으로 해야될까?
왼쪽 구역에 있는 것과 오른쪽 구역에 있는 것을 분리해볼까?
일직선 상에 있는 것은 없다고 했다.
그러면 제일 아래부터 하나씩 가져가면 되는 거 아닌가.

10^6
1000000

그러게 이러면

'''
n=int(input())
V=int(1e6)
dp={}
for i in range(1,3*n+1):
    a,b=map(int,input().split())
    dp[b+V]=dp.get(b+V,[])
    dp[b+V].append((a,i))
count=0
for keys in sorted(dp.keys()):
    for j in sorted(dp[keys]):
        print(j[1],end=' ')
        count+=1
        if count==3:
            count=0
            print()