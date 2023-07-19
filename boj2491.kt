import kotlin.math.max
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val dp=Array(n+1){ arrayOf(1,1) }
    val arr= mutableListOf<Int>()
    var result=0
    repeat(n){
        val num =r()
        arr.add(num)
        if(it>=1){
            if(arr[it] > arr[it-1]){
                dp[it][1]=dp[it-1][1]+1
                dp[it][0]=1
            }else if(arr[it]<arr[it-1]){
                dp[it][0]=dp[it-1][0]+1
                dp[it][1]=1
            }
            if(arr[it]==arr[it-1]){
                dp[it][1]=dp[it-1][1]+1
                dp[it][0]=dp[it-1][0]+1
            }
        }
        result=max(result,dp[it][1])
        result=max(result,dp[it][0])
    }
    print(result)
}