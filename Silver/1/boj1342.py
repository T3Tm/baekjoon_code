import sys
input = sys.stdin.readline

# file = open('test.input', 'r')
# file1 = open('test.output', 'w')
# input = file.readline
# print = file1.write

word = [*input().strip()]
word.sort()

cnt = 0

def confirm(comb):
    for idx in range(1, len(comb)):
        if comb[idx - 1] == comb[idx]:
            return 0
    return 1

def bact(depth, result, avail):
    global cnt
    if depth == len(word):
        cnt += confirm(result)
        return
    alpha = [0] * 26
    for i in range(len(word)):
        if avail[i]:continue
        if alpha[ord(word[i]) - ord('a')]:continue
        avail[i] = 1
        alpha[ord(word[i]) - ord('a')] = 1
        result[depth] = word[i]
        bact(depth+1 , result, avail)
        avail[i] = 0
        result[depth] = ''

bact(0, ['']*len(word), [0]*len(word))
print(f'{cnt}')

# file.close()
# file1.close()