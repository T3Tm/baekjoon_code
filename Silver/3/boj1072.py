'''
https://www.acmicpc.net/problem/1072
1072번 게임
'''
x,y=map(int,input().split())
z=y*100//x
delta_x=0
left,right=1,x
while left<=right and z!=100:
    mid = (left+right)//2
    nowz=(y+mid)*100//(mid+x)
    if z<nowz:
        right=mid-1
        delta_x=mid
    else:
        left=mid+1
print([delta_x,-1][delta_x==0])