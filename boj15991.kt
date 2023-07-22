/*
    https://www.acmicpc.net/problem/15991
    15991번 1, 2, 3 더하기 6
    해설 -> https://www.acmicpc.net/board/view/122583
    대칭을 이루기 위해 숫자를 뒤에 더하는 느낌이 아니라
    가운데로 넣는 거 어때?
    dp[i][j][z]
    z는 항의 수가 짝수였는지 , 홀수였는지
    j는 어떤 숫자를 더하였는지

 */
const val MOD=1e9.toInt()+9
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val dp=Array(100001){Array(4){Array(2){0L} } }
    val n=r()
    dp[1][1][1]=1
    dp[2][1][0]=1
    dp[2][2][1]=1
    dp[3][1][1]=1
    dp[3][3][1]=1
    for(i in 4..100000){
        dp[i][1][0]=dp[i-1][1][1]%MOD
        dp[i][1][1]=(dp[i-1][1][0]+dp[i-1][2][0]+dp[i-1][3][0])%MOD
        dp[i][2][0]=dp[i-2][2][1]%MOD
        dp[i][2][1]=(dp[i-2][1][0]+dp[i-2][2][0]+dp[i-2][3][0])%MOD
        dp[i][3][0]=dp[i-3][3][1]%MOD
        dp[i][3][1]=(dp[i-3][1][0]+dp[i-3][2][0]+dp[i-3][3][0])%MOD
    }
    repeat(n){
        val t=r()
        bw.write("${(dp[t][1][0]+dp[t][1][1]+dp[t][2][0]+dp[t][2][1]+dp[t][3][0]+dp[t][3][1])%MOD}\n")
    }
    bw.flush()
}