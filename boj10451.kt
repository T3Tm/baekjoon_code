/*
    https://www.acmicpc.net/problem/10451
    10451번 순열 사이클
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val t=readLine().toInt()
    repeat(t){
        val n=readLine().toInt()
        val graph= Array(n){ 0 }
        for((idx,value) in readLine().split(' ').map{it.toInt()}.toIntArray().withIndex()){
            graph[idx]=value-1
        }
        val visited=Array<Boolean>(n){false}
        var cnt=0
        repeat(n){x->
            if(!visited[x]) {
                cnt++
                dfs(x,visited,graph)
            }
        }
        bw.write("$cnt\n")
    }
    bw.flush()
}

fun dfs(x: Int, visited: Array<Boolean>,g:Array<Int>){
    visited[x]=true
    val next=g[x]
    if(!visited[next])dfs(next,visited,g)
}
