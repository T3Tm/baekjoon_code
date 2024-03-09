n=int(input())
'''
1*2*3*4*5*6*7*8*9*10
15 20 25 30 35 40 45 50
'''
cnt=0
for i in range(1,n+1):
    while i%5==0:cnt,i=cnt+1,i//5
print(cnt)