'''
https://www.acmicpc.net/problem/2529
2529번 부등호
최대 9칸이 있다.
9칸에 각 0~9칸까지 들어갈 수 있다.
362880 경우의수
'''
def symbol(idx,result,numbers,avail):
    global n,maxV,minV
    if idx//2==n+1:
        num=''.join(numbers)
        maxV=max(maxV,num)
        minV=min(minV,num)
        return
    for i in range(10):
        if not avail[i]:
            if idx and eval(f'{result[idx-2]}{result[idx-1]}{i}'):
                avail[i]=1
                numbers[idx//2]=f'{i}'
                result[idx]=f'{i}'
                symbol(idx+2,result,numbers,avail)
                avail[i]=0
            elif not idx:
                avail[i]=1
                numbers[idx//2]=f'{i}'
                result[idx]=f'{i}'
                symbol(idx+2,result,numbers,avail)
                avail[i]=0
n=int(input())
word=['']+[*input()]+['']
maxV,minV='0'*(n+1),'9'*(n+1)
symbol(0,word,['0']*(n+1),[0]*(10))
print(maxV)
print(minV)