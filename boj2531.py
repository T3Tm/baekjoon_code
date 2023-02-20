'''
https://www.acmicpc.net/problem/16719
ZOAC
1. 제일 작은 아이를 찾는다.
2. 그것보다 오른쪽에 있는 인덱스들 다 출력.
3. 그것보다 왼쪽에 있는 인덱스들 다 출력.
'''
def findChar(left: int,right: int,bits: list):
    global idxArr, string
    minidx=('a',0)
    for index in range(left+1,right):
        if minidx[0]>string[index]:
            minidx=(string[index],index)
    bits[minidx[1]]=1
    for i,value in enumerate(bits):
        if value==1:print(string[i],end='')
    print()
    if minidx[1]+1<right:
        findChar(minidx[1],right,bits)
    if left+1<minidx[1]:
        findChar(left,minidx[1],bits)
string=input()
idxArr=[]
findChar(-1,len(string),[0]*len(string))