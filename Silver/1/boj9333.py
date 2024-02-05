'''
0.1 달러

'''
import decimal
decimal.getcontext().prec=9999
decimal.getcontext().rounding=decimal.ROUND_HALF_UP
import sys
readLine = sys.stdin.readline
for _ in[0]*int(readLine()):
    r,b,m=map(decimal.Decimal,readLine().split())
    answer=0
    for i in range(1,1201):
        value=round(r*b/10,1)/10
        if value>=m:break
        b+=value
        b-=m
        if b<=decimal.Decimal('0'):
            answer=i
            break
    if(answer):print(i)
    else:print('impossible')