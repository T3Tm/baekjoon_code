#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/1946
 1946번 신입 사원
 성적이 다른 사원들보다 낮으면 안 됨.
 둘 중 하나라
*/
typedef struct two{
    int paper,meet;
}two;
int t;
int cmp(void *a,void *b){
    return ((two *)a)->paper-((two*)b)->paper;
}
main(){scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        two arr[100003]={};
        for(int i=0,q,w;i<n;i++)scanf("%d %d",&q,&w),arr[i].paper=q,arr[i].meet=w;
        qsort(arr, n, sizeof(two), cmp);
        int minmeet=arr[0].meet;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i].meet<minmeet)minmeet=arr[i].meet;
            else cnt++;
        }
        printf("%d\n",n-cnt);
    }
}