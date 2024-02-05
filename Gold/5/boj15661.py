from itertools import combinations
def cal(team):
    result=0
    if(len(team)>=2):
        for comb in combinations(team,2):
            i,j=comb
            result+=graph[i][j]+graph[j][i]
    return result
n=int(input())
graph=[[*map(int,input().split())]for _ in[0]*n]
result=2000
for i in range(1,n//2+1):
    for comb in combinations(range(n),i):
        start=comb
        link=set(range(n))-set(comb)
        result=min(result,abs(cal(start)-cal(link)))
print(result)