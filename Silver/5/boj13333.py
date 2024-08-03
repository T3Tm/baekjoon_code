import sys
input = sys.stdin.readline

# file = open('test.input', 'r')
# file1 = open('test.output', 'w')
# input = file.readline
# print = file1.write

n = int(input())
number_list = [*map(int,input().split())]


k = 0
while k < 10001:
    k_cnt = set()
    n_k_cnt = set()
    for idx in range(n):
        if number_list[idx] >= k :
            k_cnt.add(idx)
        if number_list[idx] <= k:
            n_k_cnt.add(idx)
    inter_cnt = k_cnt & n_k_cnt
    if len(n_k_cnt) - len(inter_cnt) <= n - k <=len(n_k_cnt):
        left_cnt = len(n_k_cnt) - n + k
        # 전체 N에서 n-k개를 맞추기 위해 n_k_cnt에서 n-k개를 맞추고 남은 나머지
        # 만큼 
        if len(inter_cnt) >= left_cnt and len(k_cnt) - (len(inter_cnt) - left_cnt)  ==k:
            break
    k += 1
print(f'{k}')


# file.close()
# file1.close()