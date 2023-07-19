/*
  https://www.acmicpc.net/problem/9461
  9461번 파도반 수열
 */
val bw=System.out.bufferedWriter()
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}

    val n=r()
    val dp=Array(102){1L}
    dp[4]=2
    dp[5]=2
    for(i in 6..100){
        dp[i]=dp[i-1]+dp[i-5]
    }
    repeat(n){
        val t=r()
        bw.write("${dp[t]}\n")
    }
    bw.flush()
}