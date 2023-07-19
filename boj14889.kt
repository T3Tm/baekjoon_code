import kotlin.math.abs

/*
    https://www.acmicpc.net/problem/14889
    14889번 스타트와 링크
 */
val bw=System.out.bufferedWriter()
var board=arrayOf<IntArray>()
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    board=Array(n){readLine().split(' ').map{it.toInt()}.toIntArray()}
    val result=Array(n/2){0}
    var output=Int.MAX_VALUE
    fun calculate(): Int {
        var link=0
        for(i in result.indices){
            for(j in i until result.size){
                if(i==j)continue
                link+=board[result[i]][result[j]]+board[result[j]][result[i]]
            }
        }
        var start=0
        val startteam= mutableListOf<Int>()
        var idx=0
        for(i in 0 until n){
            if(idx<n/2 && result[idx]==i){
                idx++
                continue
            }
            startteam.add(i)
        }
        for(i in startteam.indices){
            for(j in i until startteam.size){
                if(i==j)continue
                start+=board[startteam[i]][startteam[j]]+board[startteam[j]][startteam[i]]
            }
        }
        return abs(start-link)
    }
    fun backt(idx:Int=0,depth:Int=0){
        if(depth == n/2){
            output=output.coerceAtMost(calculate())
            return
        }
        (idx until n).forEach{
            result[depth]=it
            backt(it+1,depth+1)
        }
    }
    backt()
    print(output)
}