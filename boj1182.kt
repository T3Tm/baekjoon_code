/*
    https://www.acmicpc.net/problem/1182
    1182번 부분수열의 합
 */
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val s=r()
    val arr=Array(n){r()}
    var cnt=0
    fun backt(depth:Int = 0,result:Int = 0,flag:Boolean=false){
        if(depth == n){
            if(result==s && flag)cnt++
            return
        }
        backt(depth+1,result+arr[depth],true)
        backt(depth+1,result,flag)
    }
    backt()
    print(cnt)
}