import java.io.BufferedReader
import java.io.InputStreamReader
/*
    https://www.acmicpc.net/problem/11726
    11726번 2xn 타일링
 */
const val MOD=10007
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val dp=Array(1002) { 0 }
    dp[1]=1
    dp[2]=2
    val n=readLine().toInt()
    for(i in 3..n){
        dp[i]=(dp[i-1]+dp[i-2])%MOD
    }
    print(dp[n])
}