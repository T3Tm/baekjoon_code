'''
table은 부모 노드 or 들어가있는지 판별
0이 저장돼있으면 누가 들어가 있는 것 
다른 양수가 들어가 있으면 해당 부분에서 처음으로 만나는 것
'''
import sys
input=sys.stdin.readline
n,q=map(int,input().split())

MAX = sys.maxsize
table=[MAX]*(n+1)
def find(num):
    global table,MAX
    cur=num
    value=(MAX,0) #숫자, 한 번이라도 0말고 바뀐 적 있는지 확인
    while cur:
        if table[cur]==MAX:pass
        elif table[cur]:value=table[cur],1
        else:value=cur,1
        cur=min(cur//2,value[0])
    table[num]=0 if value[1]==0 else value[0]
    ret = table[num]
    return [table[num],0][ret==0]

for _ in[0]*q:
    v=int(input())
    print(find(v))