from heapq import *
n,m=map(int,input().split())
arr=[*map(int,input().split())]
heaparr=[]
for i in arr:heappush(heaparr,(i,i))
result=0
while m:
    value=heappop(heaparr)
    result=value[0]
    heappush(heaparr,(value[0]+value[1],value[1]))
    m-=1
print(result)