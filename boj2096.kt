import kotlin.math.*
/*
  https://www.acmicpc.net/problem/2096
  2096번 내려가기
 */
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val dp=Array(n+1){ arrayOf(arrayOf(0,0),arrayOf(0,0),arrayOf(0,0))}
    repeat(n){
        val temp1=r()
        val temp2=r()
        val temp3=r()
        dp[it+1][0][0]=min(dp[it][0][0],dp[it][1][0])+temp1
        dp[it+1][0][1]=max(dp[it][0][1],dp[it][1][1])+temp1
        dp[it+1][1][0]=min(dp[it][0][0],min(dp[it][1][0],dp[it][2][0]))+temp2
        dp[it+1][1][1]=max(dp[it][0][1],max(dp[it][1][1],dp[it][2][1]))+temp2
        dp[it+1][2][0]=min(dp[it][1][0],dp[it][2][0])+temp3
        dp[it+1][2][1]=max(dp[it][1][1],dp[it][2][1])+temp3
    }
    print("${max(max(dp[n][0][1],dp[n][1][1]),dp[n][2][1])} ${min(min(dp[n][0][0],dp[n][1][0]),dp[n][2][0])}")
}