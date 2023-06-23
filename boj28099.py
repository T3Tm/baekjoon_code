from heapq import*
import sys
input=sys.stdin.readline
for _ in[0]*int(input()):
    input()
    arr=[*map(int,input().split())]
    last=[0]*(200003)
    answer='Yes'
    T=[]
    for idx,value in enumerate(arr,1):last[value]=idx
    for idx,value in enumerate(arr,1):
        if last[value]!=idx:heappush(T,value)
        else:
            try:
                while(last[T[0]]<=idx):heappop(T)
            except:pass
        mini=''
        try:mini=T[0]
        except:mini=200001
        if mini < value:
            answer='No'
            break
    print(answer)