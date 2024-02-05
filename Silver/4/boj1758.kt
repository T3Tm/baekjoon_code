import java.io.*
import java.util.*
import kotlin.math.*
/*
    https://www.acmicpc.net/problem/1758
    1758번 알바생 강호
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val numbers=Array(n){readLine().toInt()}.sorted().reversed()
    var result=0L
    numbers.forEachIndexed{count,v->
        result+=max(v-count,0)
    }
    print(result)
}