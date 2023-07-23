/*
    https://www.acmicpc.net/problem/1904
    1을 붙여서 만든 것
    00을 붙여서 만든 것

    1 1
    2 2
    3
 */
val bw=System.out.bufferedWriter()
const val MOD=15746
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val dp=IntArray(1000001)
    dp[1]=1
    dp[2]=2
    for(i in 3..n){
        dp[i]=(dp[i-1]+dp[i-2])%MOD
    }
    print(dp[n])
}