/*
    https://www.acmicpc.net/problem/9375
    9375번 패션왕 신해빈
 */
val bw=System.out.bufferedWriter()
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val R={nextToken();sval.toString()}

    repeat(r()){
        val n=r()
        val wear= mutableMapOf<String,MutableList<String>>()
        var lines=1L
        repeat(n){
            val name=R()
            val category=R()
            wear[category]=wear.getOrDefault(category, mutableListOf())
            wear[category]?.add(name)
        }
        for((key,value) in wear){
            lines*=value.size+1
        }
        bw.write("${lines-1}\n")
    }
    bw.flush()
}