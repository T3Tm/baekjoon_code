import kotlin.math.max
/*
    https://www.acmicpc.net/problem/11501
    11501번 주식
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    repeat(r()){
        val n=r()
        var result=0L//총 가격
        val arr=Array(n){r()}
        var last=arr.last()
        for(i in arr.lastIndex downTo 0){
            if(last<arr[i]){
                last=arr[i]
            }else{//
                result+= max(last-arr[i],0)
            }
        }
        bw.write("$result\n")
    }
    bw.flush()
}