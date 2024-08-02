import sys
input = sys.stdin.readline

n = int(input())

stickers = set()

result = 0

for num in map(int,input().split()):
    if num in stickers:stickers.remove(num)
    else:stickers.add(num)
    result=max(result,len(stickers))

print(result)