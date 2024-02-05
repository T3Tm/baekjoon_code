'''
https://www.acmicpc.net/problem/14281
14281번 볼록 수열
하나의 값을 2배를 했을 때
절대로 1<=i<=N-1에 두면 안되는 경우가 있다.


arr[i] => arr[i]-1연산만 가능
하나 줄이기 연산?
바뀐 것을 계속 어떤식으로 관리해야 될까..w
'''
n=int(input())
arr=[*map(int,input().split())]
q=[]
for i in range(1,n-1):
   q.append([arr[i],i])
q.sort(key=lambda x:-x[0]) 
count=0
for i in q:
    i=i[1]
    if arr[i-1]+arr[i+1]<arr[i]*2:#해당하는 아이의 왼쪽 오른쪽으로 idx를 옮겨서 각각 괜찮은지 판별
        value = int((arr[i-1]+arr[i+1])/2)
        count,arr[i] = count+arr[i]-value,value
        if i!=1:#뒤로 가면서 이미 변경된 값들 중에서 만족하지 않는 값들을 하나하나 차근차근 다시 돌려 놓는다.
            inner=i-1
            while inner!=0 and arr[inner]*2>arr[inner-1]+arr[inner+1]:
                value = int((arr[inner-1]+arr[inner+1])/2)
                count,arr[inner] = count+arr[inner]-value,value
                inner-=1
            i=inner
print(count)