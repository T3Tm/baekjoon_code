
/*
  https://www.acmicpc.net/problem/9657
  9657번 돌 게임 3
  1,2,3,4,5,6,7,8,9
  1,2,1,2,1
 */
val bw=System.out.bufferedWriter()
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val dp=Array(1001){false}//true이면 상근이가 이기는 거임
    dp[1]=true
    dp[3]=true
    dp[4]=true
    for(i in 5..n){
        dp[i]=!dp[i-1]//일단 전에 있던 것에 반대로 승리하게 됨.
        if(!dp[i-3])dp[i]=true
        if(!dp[i-4])dp[i]=true
    }
    print(if(dp[n])"SK" else "CY")
}