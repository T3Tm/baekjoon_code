#include <stdio.h>
#define max(a,b) (a>b?a:b)
/*
 https://www.acmicpc.net/problem/10571
 10571번 다이아몬드
 lcs, lis
 */
int t,n,q,w,e,r;
typedef struct myarr{
    int w,c,len;
}myarr;
typedef struct mydp{
    int v,idx;
}mydp;
int main() {
    scanf("%d",&t);
    while(t--){scanf("%d",&n);
        mydp dp[1003]={};
        myarr arr[202]={};
        int maxlen=1;
        for(int i=0;i<n;i++)scanf("%d.%d %d.%d",&q,&w,&e,&r),arr[i].w=q*10+w,arr[i].c=e*10+r,arr[i].len=1;
        for(int i=0;i<n;i++){int templen=1;
            for(int j=0;j<arr[i].w;j++){
                if(dp[j].v>=templen){int idx=dp[j].idx;
                    if(arr[i].c<arr[idx].c)templen=dp[j].v+1;
                }
            }
            if(dp[arr[i].w].v<templen)dp[arr[i].w].v=templen,dp[arr[i].w].idx=i;
            else if(dp[arr[i].w].v==templen){//값이 동일할 때는
                if(arr[dp[arr[i].w].idx].c < arr[i].c)dp[arr[i].w].idx=i;
            }
            maxlen=max(maxlen,templen);
        }
        printf("%d\n",maxlen);
    }
}