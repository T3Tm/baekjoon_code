'''
https://www.acmicpc.net/problem/22859
22859 HTML 파싱
1. <div> 태그 에는 무조건 하나의 문장인 <p> 태그가 있다. (다른 거 없음)
2. <p> 태그 에는 다른 태그들은 무시한다.
    2-1 p태그에 문장 시작과 끝에 공백이 있으면 지워라.
    2-2 공백이 두 개 연속으로 붙어있으면 하나의 공백으로 교체
    2-3 문장에는 알파벳, 공백만 주어짐.
3. <div>태그의 문단제목은  알파벳, 공백, 언더바만 구성돼있음(시작,끝 공백 x)
    3-1 div에는 title이 반드시 존재한다.
4. 태그표시에는 소문자, 공백, 슬래시만 이뤄져있음
'''
words=input()
tag=''
idx=0
while idx<len(words):
    word=words[idx]
    if word=='<':
        idx+=1
        continue
    elif word=='>':#태그들 무엇인지 알아내기
        if 10<=len(tag) and tag[9]=='=':
            #태그에는 소문자와 공백 슬래시만 들어갈 수 있다.
            #무조건 div 태그임.
            print(f'title : {tag[11:-1]}')#문단 제목임.
            tag=''#태그 초기화
            idx+=1
            continue
        elif len(tag)==1 and tag[0] == 'p':
            #p 태그위치
            sentance=''
            inner=idx=idx+1
            innerTag=''
            while 1:#sentance에 p내에 문장을 쌓기
                if words[inner]=='<':#어떤 태그인지 확인
                    inner+=1
                    while words[inner]!='>':# >이면 나오기
                        innerTag+=words[inner]
                        inner+=1
                    inner+=1#하나 더 증가시키기
                    if innerTag=='/p':#태그 끝 이제 문장 빠져나오기
                        break
                    else:#p태그 끝이 아니면 상관없이 태그들은 없애야함.
                        innerTag=''
                    continue
                if not (len(sentance)>=1 and sentance[-1]==' ' and words[inner]==' '):
                    #공백 두개 연속으로 들어오면 넣지 말기
                    sentance+=words[inner]
                inner+=1
            for idx,value in enumerate(sentance):
                if idx==0 or idx==len(sentance)-1:
                    if value==' ':continue
                print(value,end='')
            print()
            tag=''
            idx=inner
            continue
        else:#main 태그, /div 태그
            tag=''
            idx+=1
            continue
    tag+=word
    idx+=1