#include <stdbool.h>
/*
 https://www.acmicpc.net/problem/10973
 10973번 이전 순열
*/

int n;
int arr[10002];
bool avail[10002];
bool first=1;
void backt(int depth){
    if(depth==n){
        if(!first){
            for(int i=0;i<n;i++)printf("%d ",arr[i]);
            exit(0);
        }
        first=0;
        return;
    }
    int idx=n;
    if(first){
        avail[arr[depth]]=1;
        backt(depth+1);
        idx=arr[depth]-1;
        avail[arr[depth]]=0;
        arr[depth]=0;
    }
    for(int i=idx;i>=1;i--){
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
