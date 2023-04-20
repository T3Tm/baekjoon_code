'''
https://www.acmicpc.net/problem/1969
1969번 DNA
'''
import sys
input = sys.stdin.readline
n, m = map(int, input().split())
t = { i: {'T':0,'A' : 0,'G' : 0,'C' : 0}for i in range(m) }
result = ''
for i in[0] * n:
word = input().rstrip()
for idx, i in enumerate(word) : t[idx][i] += 1
answer = 0
for idx, value in t.items() :
    a = sorted(value.items(), key = lambda x : (-x[1], x[0]))
    result += a[0][0]
    answer += n - a[0][1]
    print(result)
    print(answer)