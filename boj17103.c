#include <stdbool.h>
/*
 https://www.acmicpc.net/problem/17103
 17103번 골드바흐 파티션
*/
int t,n;
bool prime[1000000];
main(){scanf("%d",&t);
    prime[0]=prime[1]=1;
    for(int i=2;i*i<=1000000;i++){
        if(prime[i])continue;
        for(int j=i*i;j<=1000000;j+=i){
            prime[j]=1;
        }
    }
    while(t--){
        int cnt=0;
        scanf("%d",&n);
        for(int j=2;j<=n/2;j++){
            if(!prime[j] && !prime[n-j])cnt++;
        }
        printf("%d\n",cnt);
    }
}
