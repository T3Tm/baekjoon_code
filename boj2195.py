s=input()
p=input()
answer=idx=0
while idx < len(p):#맞는 것부터 뒤로 갈 수록 갯수 세주기
    can=0,-1,-1
    for i,value in enumerate(s):
        if value == p[idx]:#지금 같으면 여기서 부터 뒤로 갈수록 짧게 copy할 수 있는 거임
            inner,inneridx=i,idx
            innercnt=0
            while inner < len(s) and inneridx < len(p) and s[inner]==p[inneridx]:
                innercnt+=1
                inner+=1
                inneridx+=1
            if can[0] < innercnt:
                can = innercnt,inner,inneridx
    answer+=1
    idx=can[2]
print(answer)