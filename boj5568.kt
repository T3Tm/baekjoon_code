/*
    https://www.acmicpc.net/problem/5568
    5568번 카드 놓기
 */
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val map=mutableMapOf<Int,Int>()
    val n=r()
    val k=r()
    val arr=Array(n){r()}
    fun backtracking(depth:Int=0,avail:Array<Boolean> = Array(n){false},result:Array<String> = Array(n){""}){
        if(depth==k){
            val sb=StringBuilder()
            result.forEach { sb.append(it)}
            val value =sb.toString().toInt()
            map[value]=map.getOrDefault(value,0)+1
            return
        }
        (0 until n).forEach{i->
            if(!avail[i]){
                avail[i]=true
                result[depth]=arr[i].toString()
                backtracking(depth+1,avail,result)
                avail[i]=false
            }
        }
    }
    backtracking()
    print(map.size)
}