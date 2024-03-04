#n에서 x로 나누어 떨어지는 가장 가까운 수 구하기 36퍼틀..?
f=lambda:map(int,input().split())
n,m=sorted(f())
x,y=f()
x=abs(x)#x가 음수일 때만 start의 범위가 달라짐
start=n//x*x+y
if start<n:start+=x
result=start
#1. M넘어가는지
#2. start에서 + x 더했을 때  M안에 있는지
#3. 애초에 조건이 성립 안 했는지
if not (0<=y<x) or start>m or start+x<=m:result = 'Unknwon Number'
print(result)