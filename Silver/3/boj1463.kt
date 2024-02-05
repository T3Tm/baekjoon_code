import java.io.*
import kotlin.math.min

/*
    https://www.acmicpc.net/problem/1463
    1463번 1로 만들기
 */
val bw=BufferedWriter(OutputStreamWriter(System.out))
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val dp=Array(n+1){0}
    for(i in 2..n){
        dp[i]=dp[i-1]+1
        if(i%2==0){
            dp[i]=min(dp[i/2]+1,dp[i])
        }
        if(i%3==0){
            dp[i]=min(dp[i/3]+1,dp[i])
        }
    }
    bw.write("${dp[n]}")
    bw.flush()
}
