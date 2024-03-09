import sys,math
input = sys.stdin.readline
for _ in[0]*int(input()):
    a,b=map(int,input().split())
    print(math.lcm(a,b))