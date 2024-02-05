import java.io.BufferedWriter
import java.io.OutputStreamWriter
import java.util.LinkedList

/*
    https://www.acmicpc.net/problem/5567
    5567번 결혼식
 */
val bw=BufferedWriter(OutputStreamWriter(System.out))
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val m=readLine().toInt()
    val graph=Array(n+1){mutableListOf<Int>()}
    repeat(m){
        val (a,b)=readLine().split(' ').map{it.toInt()}
        graph[a].add(b)
        graph[b].add(a)
    }
    val cnt=bfs(n,graph)
    bw.write("$cnt")
    bw.flush()
}
fun bfs(n:Int,graph:Array<MutableList<Int>>):Int{
    val visited=Array(n+1){-1}
    visited[1]=0
    var cnt=0
    val q= LinkedList<Int>()
    q.push(1)
    while(!q.isEmpty()){
        val front=q.poll()
        for(next in graph[front]){
            if(visited[next]!=-1)continue
            visited[next]=visited[front]+1
            if(visited[next]<=2)cnt++
            q.offer(next)
        }
    }
    return cnt
}