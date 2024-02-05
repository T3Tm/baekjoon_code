#define max(a,b)(a>b?a:b)
int n,k;
int arr[1000002];
main(){scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    int left=0,len=0,cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]%2)cnt++;
        while(cnt>k)if(arr[left++]%2)cnt--;
        len=max(len,i-left+1-cnt);
    }
    printf("%d",len);
}
