word = '0'+input()
total = None
if word[1] == '0':
    if len(word)>2 and word[2]!='0':
        total = 1
    else:
        total = 0
def retCnt(num, idx):
    dp = [0]*40 #갯수 지정
    dp[0] = 1
    for i in range(1,idx+1):    
        for j in range(i):#1한개 자르기 i개 자르기까지
            n = word[i-j:i+1]
            if n != f'{int(n)}':continue 
            if 0<=int(n)<num:
                dp[i] += dp[i-j-1]
    return dp[idx]
if total==None:
    total=0
    for i in range(1,len(word)-1):
        num = word[i+1:]
        if num != f'{int(num)}':continue
        num = int(num)
        total += retCnt(num,i)
print(total)