#include <string.h>
#include <stdlib.h>
/*
 https://www.acmicpc.net/problem/1431
 1431번 시리얼 번호
*/
int n;
char arr[52][52];
int cmp(void* a,void*b){
    int sa=0;
    int sb=0;
    int sat=0,sbt=0;
    for(int i=0;((char *)a)[i];i++){
        sa++;
        if(((char *)a)[i]<=57)sat+=((char *)a)[i]-'0';
    }
    for(int i=0;((char *)b)[i];i++){
        sb++;
        if(((char *)b)[i]<=57)sbt+=((char *)b)[i]-'0';
    }
    if(sa<sb)return -1;
    else if(sa>sb)return 1;
    else if(sa==sb){
        if(sat>sbt)return 1;
        else if(sat<sbt)return -1;
    }
    return strcmp(((char *)a),((char *)b));
}
main(){scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%s",arr[i]);
    qsort(arr,n,sizeof(arr[0]),cmp);
    for(int i=0;i<n;i++)printf("%s\n",arr[i]);
}