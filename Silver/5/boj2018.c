/*
 https://www.acmicpc.net/problem/2018
 2018번 수들의 합 5
*/
int n;
long long cnt;
main(){scanf("%d",&n);
    int left=1,right=1,sum=0;
    while(right<=n+1){
        if(sum<n){
            sum+=right;
            right++;
        }
        else if(sum==n){
            sum+=right;
            cnt++,right++;
        }
        else if(sum>n){
            sum-=left;
            left++;
        }
    }
    printf("%d",cnt);
}