#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/15663
 15663번 N과 M (9)
 */
int n,m;
int arr[10];
int temp[10];
bool avail[10];
bool cmp(void *a,void *b){
    return *(int *)a>*(int *)b;
}
void pick(int depth,int result[]){
    if(depth==m){
        for(int i=0;i<m;i++){
            printf("%d ",result[i]);
        }
        printf("\n");
        return;
    }
    bool check[10002]={};
    for(int i=0;i<n;i++){
        if(!check[arr[i]] && !avail[i]){
            check[arr[i]]=1;
            avail[i]=1;
            result[depth]=arr[i];
            pick(depth+1,result);
            avail[i]=0;
            result[depth]=0;
        }
    }
}
main(){scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    qsort(arr,n,4,cmp);
    pick(0,temp);
}