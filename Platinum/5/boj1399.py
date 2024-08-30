import sys
input = sys.stdin.readline

t = int(input())

def dig(num):
    now = num
    while now > 9:
        l = now
        check = 0
        while l:
            check += l%10
            l//=10
        now = check
    return now
for _ in range(t):
    k, m = map(int, input().split())
    dx = [0,1,0,-1]
    dy = [1,0,-1,0]
    cycle = {0: [0,0]}#dx, dy
    #1. 사이클 알아내기
    #2. k 사이클이 들어갈 수 있는 만큼 몫을 구해서 몫만큼 움직이기
    #3. k % cycle을 구하고 남은 수만큼 해당 수 만큼 움직이기
    idx = 1
    now = 1
    dir = 0
    cycle_save = {}
    cycle_last = -1
    while 1:#움직이는 칸
        num = dig(now)
        if num in cycle_save:
            cycle_last = cycle_save[num]
            break#사이클 발생
        cycle_save[num] = idx
        cycle[idx] = [cycle[idx - 1][0] + dx[dir] * num, cycle[idx - 1][1] + dy[dir]*num, num]
        dir = (dir + 1) % 4
        idx += 1
        now *= m
    cycle_len = (idx-1) - cycle_last + 1
    if (cycle_len % 4)&1:
        for i in range(3):
            for j in range(idx, idx+cycle_len):
                cycle[idx] = [cycle[idx - 1][0] + dx[dir] * cycle[j - cycle_len][2], cycle[idx - 1][1] + dy[dir]*cycle[j - cycle_len][2], cycle[j - cycle_len][2]]
                idx+=1
                dir = (dir + 1)%4
    elif (cycle_len % 4) == 2:#한 번만
        for j in range(idx, idx+cycle_len):
            cycle[idx] = [cycle[idx - 1][0] + dx[dir] * cycle[j - cycle_len][2], cycle[idx - 1][1] + dy[dir]*cycle[j - cycle_len][2], cycle[j - cycle_len][2]]
            idx+=1
            dir = (dir + 1)%4
    x = 0
    y = 0
    if k < idx:
        print(cycle[k][0], cycle[k][1])
    else:
        x = cycle[cycle_last - 1][0]
        y = cycle[cycle_last - 1][1]
        k -= cycle_last - 1
        cycle_len = (idx - 1) - cycle_last + 1
        div = k // cycle_len
        x = (cycle[idx - 1][0] - x) * div + x
        y = (cycle[idx - 1][1] - y) * div + y
        x += cycle[k % cycle_len + (cycle_last -1)][0]
        y += cycle[k % cycle_len + (cycle_last -1)][1]
        print(x - cycle[cycle_last - 1][0], y - cycle[cycle_last - 1][1])