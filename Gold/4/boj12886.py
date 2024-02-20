'''
https://www.acmicpc.net/problem/12886
12886번 돌 그룹
'''
from collections import deque
a = map(int,input().split())
pre = set()
q = deque([[*a]])
pre.add(tuple(a))
res = 0
if sum(a)%3 != 0 :
    res = 0
else:    
    while q:
        a,b,c = q.popleft()
        if a == b == c:
            res = 1
            break
        a,b,c = sorted([a,b,c])
        for (x,y),z in ((a,b),c),((b,c),a),((a,c),b):
            if x != y:
                num = (x*2,y-x,z)
                if num not in pre:
                    pre.add(num)
                    q.append(num)
print(res)