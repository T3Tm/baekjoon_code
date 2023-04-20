'''
https://www.acmicpc.net/problem/1343
1343번 폴리오미노
'''
word=input().replace('XXXX','AAAA').replace('XX','BB')
print('-1'if 'X' in word else word)