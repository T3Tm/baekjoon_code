import java.util.*
/*
    https://www.acmicpc.net/problem/14442
    14442번 벽 부수고 이동하기 2
 */
val bw=System.out.bufferedWriter()
val dx=arrayOf(0,0,1,-1)
val dy=arrayOf(1,-1,0,0)
data class my(val x:Int,val y:Int, var wall:Int)
fun main() =System.`in`.bufferedReader().run{
    val (n,m,k)=readLine().split(' ').map{it.toInt()}
    val board=Array(n){readLine()}
    fun move(x:Int=0,y:Int=0):Int{
        val visited=Array(k+1){Array(n){IntArray(m){-1} }}
        visited[0][x][y]=1
        val q= LinkedList<my>()
        q.push(my(x,y,0))
        while(q.isNotEmpty()){
            val (x,y,wall)=q.poll()
            if(x==n-1 && y==m-1){
                return visited[wall][x][y]
            }
            for(i in 0..3){
                val nx=x+dx[i]
                val ny=y+dy[i]
                if(nx<0 || nx>=n || ny<0 || ny>=m)continue
                if(board[nx][ny]=='1'){
                    if(wall==k || visited[wall+1][nx][ny]!=-1)continue
                    visited[wall+1][nx][ny]=visited[wall][x][y]+1
                    q.offer(my(nx,ny,wall+1))
                    continue
                }
                if(visited[wall][nx][ny]!=-1)continue
                visited[wall][nx][ny]=visited[wall][x][y]+1
                q.offer(my(nx,ny,wall))
            }
        }
        return -1
    }
    print(move())
}
