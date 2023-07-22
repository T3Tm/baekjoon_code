/*
    https://www.acmicpc.net/problem/4811
    4811번 알약
    top Down 방식
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val dp=LongArray(31)
    val cache=Array(31){Array(31){-1L} }
    fun `Pre-processing`(w:Int,h:Int):Long{
        if(w==0 && h ==0)return 1
        if(w<0 || h < 0)return 0

        if(cache[w][h]!=-1L)return cache[w][h]
        cache[w][h]=`Pre-processing`(w-1,h+1) + `Pre-processing`(w,h-1)
        return cache[w][h]
    }
    for(i in 1..30)dp[i]=`Pre-processing`(i,0)
    while(true){
        val n=r()
        if(n==0)break
        bw.write("${dp[n]}\n")
    }
    bw.flush()
}


/*
    https://www.acmicpc.net/problem/4811
    4811번 알약
    bottom up 방식
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val dp=LongArray(31)
    dp[0]=1
    dp[1]=1
    (2..30).forEach{
        for(j in 0 until it){
            dp[it]+=dp[j]*dp[it-1-j]
        }
    }
    while(true){
        val n=r()
        if(n==0)break
        bw.write("${dp[n]}\n")
    }
    bw.flush()
}