/*
  https://www.acmicpc.net/problem/1495
  1495번 기타리스트

 */
val bw=System.out.bufferedWriter()
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val s=r()
    val m=r()
    val dp=Array(n+1){Array(m+1){false} }
    val arr=Array(n){r()}
    dp[0][s]=true
    for(i in 1..n){//50
        for(j in 0..m){//1000
            if(dp[i-1][j]){
                if(j-arr[i-1]>=0)dp[i][j-arr[i-1]]=true
                if(j+arr[i-1]<=m)dp[i][j+arr[i-1]]=true
            }
        }
    }
    var max=-1
    for(i in 0..m){
        if(dp[n][i])max=i
    }
    print(max)
}