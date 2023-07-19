/*
    https://www.acmicpc.net/problem/2847
    2847번 게임을 만든 동준이
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val s= mutableListOf<Int>()
    var result=0
    repeat(n){
        val t=readLine().toInt()
        s.add(t)
    }
    var top=s.last()
    while(!s.isEmpty()){
        result+=max(s.last()-top,0)
        top=min(top-1,s.last()-1)
        s.removeLast()
    }
    print(result)
}