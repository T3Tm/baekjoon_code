'''
https://www.acmicpc.net/problem/10827
10827번 a^b


'''
import decimal
decimal.getcontext().prec=2000
a,b=map(decimal.Decimal,input().split())
print(f'{a**b:f}')