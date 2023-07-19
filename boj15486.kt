import kotlin.math.max
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val readLine={nextToken();nval.toInt()}
    val n = readLine()
    val dp = Array(n + 2) { 0L }
    (1..n).forEach {i->
        val t=readLine()
        val p=readLine()
        if(i+t<=n+1){
            dp[i+t]=max(dp[i]+p.toLong(),dp[i+t])
        }
        dp[i+1]=max(dp[i+1],dp[i])//이번 상담을 그냥 안 하고 넘어가도 된다.
    }
    print(dp[n+1])
}