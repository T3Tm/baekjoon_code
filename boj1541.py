'''
숫자들을 끊어서 정리할 필요가 있을듯
'''
word=input()
answer=idx=0
result=''
num=''#숫자 저장하기
while idx<len(word):
    if word[idx]!=')' and word[idx]!='+' and word[idx]!='-':
        num+=word[idx];idx+=1
        continue
    if num:result+=f'{int(num)}';num=''
    result+=word[idx]
    if word[idx]=='-':
        result+='(';idx+=1
        while idx<len(word):#숫자들은 따로 처리 해줘야됨.
            while idx<len(word) and word[idx]!='+' and word[idx]!='-':
                num+=word[idx];idx+=1
            if idx<len(word) and word[idx]=='-':
                result+=f'{int(num)}';num=''
                break
            elif idx!=len(word):result+=f'{int(num)}+';num=''
            else:result+=f'{int(num)}';num=''
            idx+=1
        result+=')'
        if idx<len(word) and word[idx]=='-':continue
        else:idx-=1;continue
    idx+=1
if num:result+=f'{int(num)}'
print(eval(result))