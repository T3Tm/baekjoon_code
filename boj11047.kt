import java.io.*
import java.util.*

/*
    https://www.acmicpc.net/problem/11047
    11047번 동전 0
 */
val bw=BufferedWriter(OutputStreamWriter(System.out))
fun main() = with(System.`in`.bufferedReader()) {
    var (n,k)=readLine().split(' ').map{it.toInt()}
    val coin=mutableListOf<Int>()
    repeat(n) {coin.add(readLine().toInt()) }
    var cnt=0
    var idx=coin.size-1
    while(k!=0){
        cnt+=k/coin[idx]
        k%=coin[idx--]
    }
    bw.write("$cnt")
    bw.flush()
}
