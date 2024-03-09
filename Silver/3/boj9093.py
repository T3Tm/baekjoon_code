import sys
input = sys.stdin.readline
word = input().strip()
idx= 0 
while idx<len(word):
    if word[idx]=='<':
        a = []
        while idx<len(word) and word[idx] !='>':
            a.append(word[idx])
            idx+=1
        tag = ''.join(a)+'>'
        print(tag,end='')
        idx+=1
        continue
    a = []
    while idx<len(word) and word[idx]!='<' and word[idx]!=' ':
        a.append(word[idx])
        idx+=1
    inner = ''.join(a[::-1])
    if idx<len(word) and word[idx]==' ':
        inner+=' '
        idx+=1
    print(inner,end='')