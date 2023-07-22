/*
    https://www.acmicpc.net/problem/1309
    1309번 동물원
 */
val bw=System.out.bufferedWriter()
const val MOD=9901
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    nextToken()
    val n= nval.toInt()
    val dp= IntArray(n+1)
    dp[0]=1
    dp[1]=3
    (2..n).forEach{i->
        dp[i]=(dp[i-1]*2+dp[i-2])%MOD
    }
    print(dp[n])
}
