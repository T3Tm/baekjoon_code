/*
    https://www.acmicpc.net/problem/2302
    2302번 극장 좌석
 */
val bw=System.out.bufferedWriter()
val dp=Array(41){1}
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val m=readLine().toInt()
    dp[2]=2
    for(i in 3..n)dp[i]=dp[i-1]+dp[i-2]
    var result=1
    var front=0
    repeat(m){
        val t=readLine().toInt()
        result*=dp[t-front-1]
        front=t
    }
    result*=dp[n-front]
    print(result)
}