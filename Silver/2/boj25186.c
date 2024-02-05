#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 https://www.acmicpc.net/problem/25186
 25186번 INFP 두람
  사진을 찍는 모두가 이웃한 두 사람과 옷이 겹치지 않아야 한다.
 제일 큰 애들 먼저 서면서 값을 보면됨.
 */
int cmp(const void *a,const void *b){
    int A = *(int *)a;
    int B = *(int *)b;
    return B>A;
}
char result[9] ="Happy";
int n,arr[(int)1e5+3];
long long a,b;
main(){scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    qsort(arr,n,4,cmp);
    a=arr[0],b=(n==1?1:0);
    for(int i=1;i<n;i++)b+=arr[i];
    if(a>b)strcpy(result,"Unhappy");
    printf("%s",result);
}