'''
https://www.acmicpc.net/problem/2800
괄호제거
'''
from itertools import combinations
words = input()
parentheses = [] # 튜플로 괄호 인덱스 쌍들
pair = [] #순서대로 쌍 구하는 짝
result = set() #모든 순서쌍 중복 없이
for idx,word in enumerate(words):
    if word =='(':
        pair.append(idx)
    elif word == ')':
        parentheses.append((pair.pop(),idx))
for number in range(1,len(parentheses)+1): #갯수
    for combs in combinations(parentheses,number): #조합
        idxs=() #인덱스들
        for comb in combs:idxs+=comb
        newword=''
        for idx,i in enumerate(words):
            if idx in idxs:continue #words의 idx 중 괄호 인덱스가 있으면 추가하기 말고 건너띄기
            newword+=i
        result.add(newword) #쌍 result에 추가
for comb in sorted(result):#사전 순
    print(comb)