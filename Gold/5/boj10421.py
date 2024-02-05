def check(n,idx):
    global line,exceptNumbers
    if len(str(n))!=line[idx]:return 1
    while n:
        compare=n%10
        if compare in exceptNumbers:return 1
        n//=10
    return 0
def pickB(depth,result,a):
    global line,exceptNumbers,count,numbers
    if depth==line[1]:
        if(not check(result*a,depth+2)):count+=1
        return
    for value in numbers:
        next=value*(10**depth)+result
        if(check(value*a,depth+2)):continue
        pickB(depth+1,next,a)
def pickA(depth,result):
    if depth==line[0]:
        pickB(0,0,result)
        return
    for value in numbers:
        pickA(depth+1,value*(10**depth)+result)
n=int(input())
line=[*map(int,input().split())]
k=int(input())
numbers=[*map(int,input().split())]
exceptNumbers=set(range(10))-set(numbers)
count=0
pickA(0,0)
print(count)