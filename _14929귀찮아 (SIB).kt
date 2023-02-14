import java.math.BigInteger
import java.util.*
/*
https://www.acmicpc.net/problem/14929
귀찮아 (SIB)
n<=10만 이하  , |x_i|<=100
* */
fun main() = with(System.`in`.bufferedReader()){
    var n = readLine().toInt()
    val st = StringTokenizer(readLine())
    var arr = Array(n){st.nextToken().toInt()}
    var dp = Array(n+2){0}
    var sum :BigInteger=BigInteger("0")
    for(i in n downTo 1){
        dp[i]=dp[i+1]+arr[i-1]
    }
    for(i in n-1 downTo 1){
        dp[i+1]=dp[i+1]*arr[i-1]
        sum+=dp[i+1].toBigInteger()
    }
    print(sum)
}