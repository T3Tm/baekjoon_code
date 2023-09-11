'''
https://www.acmicpc.net/problem/4375
4375번 1


1로 이뤄져 있다..?

'''
import sys
for i in map(int,sys.stdin.readlines()):
    tmp=0
    for j in range(i):
        tmp=tmp*10+1
        tmp%=i
        if tmp==0:
            print(j+1)
            break