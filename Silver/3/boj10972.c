#include <stdbool.h>
/*
 https://www.acmicpc.net/problem/10972
 10972번 다음 순열
*/

int n;
int arr[10002];
bool avail[10002];
bool first=1;
void backt(int depth){
    if(depth==n){
        if(!first){
            for(int i=0;i<n;i++){
                printf("%d ",arr[i]);
            }
            exit(0);
        }
        first=0;
        return;
    }
    int idx=1;
    if(first){
        avail[arr[depth]]=1;
        backt(depth+1);
        idx=arr[depth]+1;
        avail[arr[depth]]=0;
        arr[depth]=0;
    }
    for(int i=idx;i<=n;i++){//-5,-4,-3,-2,-1
        if(!avail[i]){
            avail[i]=1;
            arr[depth]=i;
            backt(depth+1);
            avail[i]=0;
            arr[depth]=0;
        }
    }
}
main(){scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    backt(0);
    printf("-1");
}
