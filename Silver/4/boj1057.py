'''
https://www.acmicpc.net/problem/1057
1057번 토너먼트
'''
import math;C=math.ceil
n,kim,im=map(int,input().split())
kim,im=min(kim,im),max(kim,im)
cnt=1
while not(im%2==0 and im-1==kim):
    kim,im=C(kim/2),C(im/2)
    cnt+=1
print(cnt)