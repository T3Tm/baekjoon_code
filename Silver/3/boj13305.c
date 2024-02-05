#include <limits.h>
#define min(a,b)(a>b?b:a)
#define ll long long
/*
 https://www.acmicpc.net/problem/13305
 13305번 주유소
 
*/
int n;
ll arr[100002],arr1[100002];
ll result;
main(){scanf("%d",&n);
    for(int i=0;i<n-1;i++)scanf("%lld",&arr1[i]);
    for(int i=0;i<n;i++)scanf("%lld",&arr[i]);
    ll minv=LONG_MAX;
    for(int i=0;i<n-1;i++){
        minv=min(minv,arr[i]);
        result+=minv*arr1[i];
    }
    printf("%lld",result);
}
