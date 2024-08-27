n, k = map(int,input().split())

a = input()
b = input()


p = [11, 13]
m = [10**9 + 7, 10**9 + 9]

p_pow = [[0]*k for _ in range(2)]

for l in range(2):
    p_pow[l][0] = 1
    for i in range(1, k):#k
        p_pow[l][i] = p_pow[l][i-1] * p[l] % m[l]

def to_int(ch):
    return ord(ch) - ord('1') + 1

hash = [0,0]
for l in range(2):
    for i in range(k):
        hash[l] = (hash[l] + to_int(a[i]) * p_pow[l][k - i - 1])%m[l]

aa = {tuple(hash) : 0}
for i in range(1, n - k + 1):
    for l in range(2):
        hash[l] = ((hash[l] - to_int(a[i-1])*p_pow[l][-1])*p[l] + to_int(a[i+k-1]) + m[l])%m[l]
        aa[tuple(hash)] = 0

b_hash = [0,0]
for l in range(2):
    for i in range(k):
        b_hash[l] = (b_hash[l] + to_int(b[i]) * p_pow[l][k - i- 1])%m[l]
if tuple(b_hash) in aa:
    aa[tuple(b_hash)] = 1

for i in range(1, n - k + 1):
    for l in range(2):
        b_hash[l] = ((b_hash[l] - to_int(b[i-1])*p_pow[l][-1])*p[l] + to_int(b[i+k-1])+ m[l])%m[l]
    if tuple(b_hash) in aa:
        aa[tuple(b_hash)] = 1
print([*aa.values()].count(1))