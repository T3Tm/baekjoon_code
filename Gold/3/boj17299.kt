/*
    https://www.acmicpc.net/problem/17299
    17299번 오등큰수
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val F=Array(1000001){0}
    val arr=Array(n){val t=r();F[t]++;t}
    val s= mutableListOf<Pair<Int,Int>>()
    val result=Array(n){-1}
    arr.forEachIndexed{idx,v->
        while(s.isNotEmpty() && F[s.last().second]<F[v]){
            val (index,value)=s.removeLast()
            result[index]=v
        }
        s.add(Pair(idx,v))
    }
    result.forEach { bw.write("$it ") }
    bw.flush()
}
