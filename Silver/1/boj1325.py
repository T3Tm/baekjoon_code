import sys
input = sys.stdin.readline
# file = open('test.input', 'r')
# file1 = open('test.output', 'w')
# input = file.readline
# print = file1.write

n, m = map(int, input().split())

graph = [[]for _ in range(n+1)]

for _ in range(m):
    a, b = map(int,input().split())
    graph[b].append(a)

result_depth = 0
result_list = []

visited = [0] * (n + 1) # 방문을 했는지 체크

for i in range(1, n + 1): #n번
    computer_cnt = 0
    
    s = [i]
    visited[i] = i
    while s:
        cur = s.pop()
        for next in graph[cur]:
            if visited[next] == i:continue
            s.append(next)
            visited[next] = i
            computer_cnt += 1
            
    if computer_cnt > result_depth:
        result_depth = computer_cnt
        result_list = [i]
    elif computer_cnt == result_depth:
        result_list.append(i)

result_list.sort()
print(*result_list)

# file.close()
# file1.close()