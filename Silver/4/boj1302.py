names={}
for _ in[0]*int(input()):
    name=input()
    names[name]=names.get(name,0)+1
print(sorted(names.items(),key=lambda x:(-x[1],x[0]))[0][0])