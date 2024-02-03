#include <stdio.h>
int len(int src){
    int cnt=0;
    while(cnt++,src/=10);
    return cnt;
}
main(){
    int l,r; scanf("%d %d",&l,&r);
    int len_l = len(l) , len_r = len(r);
    int result = len_l;
    int compare[]={0,1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
    if(len_l != len_r){
        result = 0;
    }else{
        int cnt=0;
        for(int i=len_l;i>=1;i--){
            if (l/compare[i] != r/compare[i]){
                break;
            }
            if(l/compare[i] == 8)cnt++;
            l%=compare[i];
            r%=compare[i];
        }
        result=cnt;
    }
    printf("%d",result);
}