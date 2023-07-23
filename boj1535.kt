import kotlin.math.max
/*
    https://www.acmicpc.net/problem/1535
    1535번 안녕
 */
data class my(val lose:Int, var happy:Int):Comparable<my>{
    override fun compareTo(other: my)=if(this.lose!=other.lose)this.lose-other.lose else this.happy-other.happy
}
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val arr=Array(n){my(r(),0)}
    repeat(n){arr[it].happy=r()}
    arr.sort()
    val dp=IntArray(101)
    for((l,h) in arr){
        for(j in 100 downTo l+1){
            if(dp[j-l]!=0){
                dp[j]=max(dp[j],dp[j-l]+h)
            }else dp[j]=max(dp[j],h)
        }
    }
    print(dp.max())
}