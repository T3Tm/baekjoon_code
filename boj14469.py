'''
도착 시간, 검문 시간
2 3
c>a
c+b or 
'''
c=0
for a,b in sorted((*map(int,input().split()),)for _ in[0]*int(input())):c=max(c,a)+b
print(c)