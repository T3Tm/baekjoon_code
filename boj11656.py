'''
https://www.acmicpc.net/problem/11656
11656번 접미사 배열
'''
word=input()
tmp=''
li=[]
for i in word[::-1]:
    tmp=i+tmp
    li.append(tmp)
print(*sorted(li),sep='\n')