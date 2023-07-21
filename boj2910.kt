/*
    https://www.acmicpc.net/problem/2910
    2910번 빈도 정렬
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val arr=mutableMapOf<Int,Int>()
    val n=r()
    val c=r()
    repeat(n){val t=r();arr[t]=arr.getOrDefault(t,0)+1}
    val now=arr.toList().sortedBy { it-> -it.second}
    for((key,value) in now){
        repeat(value){
            bw.write("$key ")
        }
    }
    bw.flush()
}