n,k=map(int,input().split())
arr=[*map(int,input().split())]
left,right=0,int(1e9)
while left<=right:
  mid=(left+right)//2
  count=set()
  for i in range(1,n):
    if abs(arr[i]-arr[i-1])>mid:
      count.add(i)
      count.add(i-1)
  if len(count)<=k:
    right=mid-1
  else:
    left=mid+1
print(left)