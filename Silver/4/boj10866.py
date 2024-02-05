import sys
from collections import deque
input=sys.stdin.readline
a=deque()
for _ in[0]*int(input()):
    cmd,*_=input().split()
    if cmd[0]=='p':
        if cmd[1]=='u':
            if cmd[5]=='f':
                a.appendleft(int(_[0]))
            else:
                a.append(int(_[0]))
        else:
            if a:
                if cmd[4]=='f':
                    print(a.popleft())
                else:
                    print(a.pop())
            else:
                print(-1)
    elif cmd[0]=='s':
        print(len(a))
    elif cmd[0]=='e':
        print(0 if a else 1)
    elif cmd[0]=='f':
        if a:
            print(a[0])
        else:
            print(-1)
    else:
        if a:
            print(a[-1])
        else:
            print(-1)