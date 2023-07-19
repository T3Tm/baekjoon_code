import java.util.*
/*
    https://www.acmicpc.net/problem/5014
    5014번 스타트링크
 */
fun main() = with(System.`in`.bufferedReader()) {
    val(F, S, G, U, D)=readLine().split(' ').map{it.toInt()}
    fun bfs():String {
        val visited=Array(F+1){-1}
        visited[S]=0
        val q= LinkedList<Int>()
        q.offer(S)
        while(!q.isEmpty()){
            var cur=q.poll()
            if(cur==G)return visited[G].toString()
            for(next in arrayOf(cur+U,cur-D)){
                if(next<1 || next>F)continue
                if(visited[next]!=-1)continue
                visited[next]=visited[cur]+1
                q.offer(next)
            }
        }
        return "use the stairs"
    }
    print(bfs())
}