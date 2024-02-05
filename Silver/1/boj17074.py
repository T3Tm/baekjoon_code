'''
https://www.acmicpc.net/problem/17074
17074번 정렬

arr[i]가 정렬이 됐는지 안 됐는지 알 수 있는 방법은

arr[:i] + arr[i+1:]
이렇게 인데
앞이 정렬됐는지, i+1이 정렬됐는지
arr[i-1] + arr[i+1]이 정렬 됐는지 확인

1,2,3,6,5,

arr[i]의 정렬 상태는 전에 값에 자기가 연결이 되는지 확인

정렬, 1,3정렬 상태 , 3,4정렬 상태
dp의 상태 + arr[i-1] + arr[i]가 

'''
import sys
sys.setrecursionlimit(100000)
def check(idx,plus):#
    global arr,n,sorted_dp
    if plus==1:
        if sorted_dp[idx][0]!=-1:
            return sorted_dp[idx][0]
    else:
        if sorted_dp[idx][1]!=-1:
            return sorted_dp[idx][1]
    if idx==0:return 1
    elif idx==1:return arr[0]<=arr[1]
    elif idx==n:return arr[n]<=arr[n+1]
    elif idx==n+1:return 1
    else:#plus의 값이 앞으로 가는지 뒤로 가는지 판단
        if plus==1:
            sorted_dp[idx][0] = check(idx+1,1)& (arr[idx]<=arr[idx+1])
            return sorted_dp[idx][0]
        else:
            sorted_dp[idx][1]=check(idx-1,-1)& (arr[idx-1]<=arr[idx])
            return sorted_dp[idx][1]
V=10**9
n=int(input())
arr=[-V] + [*map(int,input().split())] + [V]
dp=[0]*(n+3)
sorted_dp=[[-1,-1]for _ in[0]*(n+3)]
for idx in range(1,n+1):#O(n)
    front = check(idx-1,-1)
    back = check(idx+1,1)
    dp[idx]=front & (arr[idx-1]<=arr[idx+1]) & back
print(sum(dp))