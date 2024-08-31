word = '#' + '#'.join(input()) + '#'

N = len(word)
A = [0]*N

r=q=-1

for i in range(1,N):
    if r>=i:
        ii = 2*q -i
        A[i] = min(r-i, A[ii])
    
    while i-A[i]-1>=0 and i+A[i]+1<N and \
        word[i-A[i]-1] == word[i+A[i]+1]:
            A[i]+=1
    if i+A[i]>r:
        r, q = i+A[i], i

cnt = 0
for i in range(1, N):
    if word[i] != '#':#해당 곳에서는 한 개 빼고 세주면 된다.
        cnt += 1
    cnt += A[i]//2
print(cnt)