word = input()
count = [0,0,0,0]
res = 1
now = 'f'
idx = 0
while idx < len(word):
    while idx < len(word) and word[idx] == 'w':
        count[0] += 1
        idx += 1
    if count[0] == 0:
        res = 0 
        break
    while idx < len(word) and word[idx] == 'o':
        count[1] += 1
        idx += 1
    if count[0] != count[1]:
        res = 0 
        break
    while idx < len(word) and word[idx] == 'l':
        count[2] += 1
        idx += 1
    if count[1] != count[2]:
        res = 0 
        break
    while idx < len(word) and word[idx] == 'f':
        count[3] += 1
        idx += 1
    if not (count[0] == count[1] == count[2] == count[3]):
        res = 0
        break
    count = [0]*4
print(res)