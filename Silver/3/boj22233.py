import sys
input = sys.stdin.readline

# file = open('test.input', 'r')
# file1 = open('test.output', 'w')
# input = file.readline
# print = file1.write

n, m = map(int,input().split())

words = set()

for _ in range(n):
    word = input().strip()
    words.add(word)

for _ in range(m):
    lists = input().strip().split(',')
    for li in lists:
        words.discard(li)
    print(len(words))

# file.close()
# file1.close()