import kotlin.math.min

/*
  https://www.acmicpc.net/problem/16194
  16194번 카드 구매하기 2
 */
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val arr=Array(n){r()}
    val dp=Array(n+1){0}
    for(j in arr.indices){
        for(i in j+1..n){
            if(dp[i]!=0)dp[i]=min(dp[i],dp[i-(j+1)]+arr[j])
            else dp[i]=dp[i-(j+1)]+arr[j]
        }
    }
    print(dp[n])
}