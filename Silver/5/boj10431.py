import sys
input = sys.stdin.readline

# file = open('test.input', 'r')
# file1 = open('test.output', 'w')
# input = file.readline
# print = file1.write

p = int(input())

def sorting(List):
    cnt = 0
    for i in range(1,20):
        for j in range(i):
            if List[j] > List[i]:
                cnt += 1
                List[j], List[i] = List[i], List[j]
    return cnt

for _ in range(p):
    case,*lists = input().split()
    lists = [*map(int, lists)]
    result = sorting(lists)
    print(f'{case} {result}')

# file.close()
# file1.close()