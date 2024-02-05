/*
    https://www.acmicpc.net/problem/16195
    16195번 1, 2, 3 더하기 9
    1.
    1

    2.

    1,1

    2

    3.
    1,1,1

    1,2
    2,1

    3
    4.
    1,1,1,1
    1,2,1
    2,1,1
    1,1,2

    2,2
    1,3
    3,1
 */
const val MOD=1e9.toInt()+9
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val dp=Array(1001){Array(1001){Array(4){0L} } }
    val t=r()
    dp[1][1][1]=1
    dp[2][1][2]=1
    dp[2][2][1]=1
    dp[3][1][3]=1
    dp[3][2][1]=1
    dp[3][2][2]=1
    dp[3][3][1]=1
    for(i in 4..1000){
        for(j in 1..1000){
            dp[i][j][1]=(dp[i-1][j-1][1]+dp[i-1][j-1][2]+dp[i-1][j-1][3])%MOD
            dp[i][j][2]=(dp[i-2][j-1][1]+dp[i-2][j-1][2]+dp[i-2][j-1][3])%MOD
            dp[i][j][3]=(dp[i-3][j-1][1]+dp[i-3][j-1][2]+dp[i-3][j-1][3])%MOD
        }
    }
    repeat(t){
        val n=r()
        val m=r()
        var result=0L
        for(j in 1..m){
            result=(result+dp[n][j][1]+dp[n][j][2]+dp[n][j][3])%MOD
        }
        bw.write("${result}\n")
    }
    bw.flush()
}