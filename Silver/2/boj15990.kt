/*
   https://www.acmicpc.net/problem/15990
   15990번 1, 2, 3 더하기 5
   연속해서 사용하면 안된다.

   전에 사용했던 아이를 알아낸다면?

   1,2,3만 가지고 가고
   dp를 한다면?
   dp[n][3]
 */
val bw=System.out.bufferedWriter()
const val MOD=1000000009
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val dp= Array(100002){arrayOf(0L,0L,0L,0L)}
    dp[1][1]=1
    dp[2][2]=1
    dp[3][3]=1
    dp[3][2]=1
    dp[3][1]=1
    for(i in 4..100000){
        dp[i][1]=(dp[i-1][2]+dp[i-1][3])%MOD
        dp[i][2]=(dp[i-2][1]+dp[i-2][3])%MOD
        dp[i][3]=(dp[i-3][1]+dp[i-3][2])%MOD
    }
    repeat(n){
        val temp=r()
        bw.write("${(dp[temp][1] + dp[temp][2] + dp[temp][3]) % MOD}\n")
    }
    bw.flush()
}