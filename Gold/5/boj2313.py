'''
https://www.acmicpc.net/problem/2313
2313번 보석 구매하기
연속적인 보석을 구매할 것이다.
구매하는 보석의 가치의 총 합이 최대가 되다.
30, 70, -10, 30 , 0
30 ,100, 100,90 ,100,120

60,-10,-20,-29,100,-40,10,1000
60,0 60,50,60,20, 60,1, 
1,1
현재 문제점은 음수를 계속 쌓아 가다가 언제 버려야 되는지가 문제
음수를 계속 쌓을 수는 없다.
그럼 음수를 쌓다가 양수가 나오는 상황 때 그 때 값을 비교를 해서 초기화를 할지 안 할지 비교하자.


'''
import sys;input=sys.stdin.readline
n=int(input())
answer=[]
total=0
for _ in[0]*n:
    n_t=int(input())
    dp=[0]*(n_t+1)
    idxs=[-1,-1]
    now_idx=[-1,-1]
    max_value=-10001
    for idx,value in enumerate(map(int,input().split()),1):
        if dp[idx-1]+value > value:#이어온 것이 더 크다는 것
            dp[idx]=dp[idx-1]+value
            now_idx[1]=idx
        else:
            dp[idx]=value
            now_idx=[idx,idx]
        if max_value < dp[idx]:
            max_value=dp[idx]
            idxs=now_idx[:]
        elif max_value == dp[idx] and idxs[1]-idxs[0] > now_idx[1]-now_idx[0]:
            idxs=now_idx[:]
    answer.append(idxs)
    total+=max_value
print(total)
for i in answer:
    print(*i)