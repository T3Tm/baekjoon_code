cnt=0
for _ in[0]*int(input()):
    a=[]
    for s in input():
        if a and a[-1]==s:a.pop()
        else:a.append(s)
    if not a:cnt+=1
print(cnt)