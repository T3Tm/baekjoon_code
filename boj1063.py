'''
https://www.acmicpc.net/problem/1063
1063번 킹

T 위 (아래로)
B 아래 (위)
'''
import sys
input = sys.stdin.readline

MOVE={'R':(0,1),'L':(0,-1),'B':(-1,0),'T':(1,0),'RT':(1,1),'LT':(1,-1),'RB':(-1,1),'LB':(-1,-1)}
k,d,n=input().split()
n=int(n)
king=[int(k[1]),ord(k[0])-64]
stone=[int(d[1]),ord(d[0])-64]
for _ in[0]*n:
    command=input().strip()
    dx,dy=MOVE[command]
    Nking=[king[0]+dx,king[1]+dy]
    Nstone=[stone[0]+dx,stone[1]+dy]
    if 1<=Nking[0]<=8 and 1<=Nking[1]<=8:
        if Nking==stone:
            if 1<=Nstone[0]<=8 and 1<=Nstone[1]<=8:
                stone=Nstone
                king=Nking
        else:king=Nking
            
            
print(f'{chr(king[1]+64)}{king[0]}')
print(f'{chr(stone[1]+64)}{stone[0]}')