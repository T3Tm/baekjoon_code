/*
  https://www.acmicpc.net/problem/15989
  15989번 1, 2, 3 더하기 4
 */
val bw=System.out.bufferedWriter()
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}

    val n=r()
    val dp=Array(10001){arrayOf(0,0,0,0)}
    dp[1][1]=1
    dp[2][1]=1
    dp[2][2]=1
    dp[3][1]=1
    dp[3][2]=1
    dp[3][3]=1
    for(i in 4..10000){
        dp[i][1]=dp[i-1][1]
        dp[i][2]=dp[i-2][1]+dp[i-2][2]
        dp[i][3]=dp[i-3][1]+dp[i-3][2]+dp[i-3][3]
    }
    repeat(n){
        val t=r()
        println(dp[t][1]+dp[t][2]+dp[t][3])
    }
}