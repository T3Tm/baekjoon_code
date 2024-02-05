import sys
words={}
for i in sys.stdin.readlines():
  for value in i.rstrip():
    if value == ' ':continue
    words[value]=words.get(value,0)+1
sortList=sorted(words.items(),key=lambda x:(-x[1],x[0]))
cnt=sortList[0][1]
for i in sortList:
  if cnt==i[1]:print(i[0],end='')
  else:break