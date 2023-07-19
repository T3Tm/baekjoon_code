/*
  https://www.acmicpc.net/problem/15681
  15681번 트리와 쿼리
 */
val bw=System.out.bufferedWriter()
data class Trees(val child:MutableList<Int>,var parent:Int){}
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val N=r()
    val R=r()
    val Q=r()
    val graph=Array(N+1){ mutableListOf<Int>()}
    val trees=Array(N+1){Trees(mutableListOf<Int>(),-1)}
    repeat(N-1){
        val u=r()
        val v=r()
        graph[u].add(v)
        graph[v].add(u)
    }
    val visited=Array(N+1){false}
    val dp=Array(N+1){-1}
    fun makeTree(x:Int,parent:Int){
        visited[x]=true
        for(node in graph[x]){
            if (node!=parent && !visited[node]){
                trees[x].child.add(node)
                trees[x].parent=x
                makeTree(node,x)
            }
        }
    }
    makeTree(R,-1)
    fun countSubTree(x:Int){
        dp[x]=1
        for(node in trees[x].child){
            countSubTree(node)
            dp[x]+=dp[node]
        }
    }
    countSubTree(R)
    repeat(Q){
        val t=r()
        bw.write("${dp[t]}\n")
    }
    bw.flush()
}