'''
https://www.acmicpc.net/problem/1312
1312번 소수
일단 정확히 떨어지는지 아닌지를 알아내야함.
그러기 위해서는 계속 0이 반복되는지 알면됨.
정확히 나누어 떨어진다면 뒤에가 계속 0으로 반복될 것이다.
'''

a,b,n=map(int,input().split())
#풀이1
if n==1:a%=b
while n!=1:
    a*=10
    a%=b
    n-=1
print(a*10//b)
#풀이2
print(a*10**n//b%10)