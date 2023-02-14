#6137
from collections import deque
import sys
readLine=sys.stdin.readline
n=int(readLine())
word=deque()
T=''
for _ in [0]*n:word.append(readLine().rstrip())
for _ in [0]*(n-1):
    if word[0]>word[-1]:T+=word.pop()
    elif word[0]==word[-1]:
        a,b=0,len(word)-1
        while a<=b:
            if word[a]==word[b]:
                a+=1
                b-=1
            elif word[a]<word[b]:
                T+=word.popleft()
                break
            else:
                T+=word.pop()
                break
        else:
            T+=word.popleft()
    else:T+=word.popleft()
T+=word.pop()
for idx,value in enumerate(T):
    if idx and not idx%80:print()
    print(value,end='')