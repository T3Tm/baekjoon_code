/*
    https://www.acmicpc.net/problem/18310
    18310번 안테나
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val arr=Array(r()){r()}.sorted()
    print(arr[(arr.size-1)/2])
}