'''
https://www.acmicpc.net/problem/9996
9996번 한국이 그리울 땐 서버에 접속하지
'''
import re
n=int(input())
p=re.compile(input().replace('*','.*')+'$')
for i in[0]*n:print("DA"if p.match(input())else"NE")