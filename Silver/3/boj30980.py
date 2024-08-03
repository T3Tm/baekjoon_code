import sys
input = sys.stdin.readline

# file = open('test.input', 'r')
# file1 = open('test.output', 'w')
# input = file.readline
# print = file1.write

n, m = map(int,input().split())
result = []

def confirm(expression, answer):
    evaled = eval(expression) #계산 결과
    return evaled == answer

def progress(first, second, last, start):
    #1. 두번째에서 일단 수식을 걸러내서 confirm에 넣는다.
    idx = start + 1
    express = ''
    while second[idx] != '=':
        express += second[idx]
        idx += 1
    
    idx += 1
    ans = ''
    while second[idx] != '.':
        ans += second[idx]
        idx += 1
    
    true_false = confirm(express, int(ans))
    
    if true_false: #true면 1부터 idx까지 다 * 처리
        for index in range(start+1,idx):
            first[index] = '*'
            last[index] = '*'
        second[start] = '*'
        second[idx] = '*'
    else:
        first[start+3] = '/'
        second[start+2] = '/'
        last[start+1] = '/'
    
    return first, second, last
for _ in range(n):#n번에 걸쳐서 3줄을 읽어야 함.
    first = [*input().strip()]
    second = [*input().strip()]
    last = [*input().strip()]
    
    #1, 9부터 시작해서 .이 들어오기 전까지 수식을 
    for start in range(0, 8*m, 8):
        first,second,last = progress(first,second,last,start)
    
    print(''.join(first))
    print(''.join(second))
    print(''.join(last))
    
# file.close()
# file1.close()