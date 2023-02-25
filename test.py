from collections import deque
s=[deque([*input()]) for _ in[0]*5]
result=''
idx=0
while len(s[0]) or len(s[1]) or len(s[2]) or len(s[3]) or len(s[4]):
    if idx==5:idx=0
    if len(s[idx])==0:
        idx+=1
        continue
    result+=s[idx].popleft()
    idx+=1
print(result)