/*
 https://www.acmicpc.net/problem/5525
 5525번 IOIOI
*/
int n,m,cnt,result;
char word[1000002];
main(){scanf("%d %d %s",&n,&m,word);
    for(int i=0;word[i];i+=2){
        if(word[i]=='I'){
            if(cnt>=n)result++;
            if(i+1<m){
                if(word[i+1]=='O')cnt++;
                else cnt=0,i--;
            }
        }else i--,cnt=0;
    }
    printf("%d",result);
}