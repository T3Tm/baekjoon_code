import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.max
import kotlin.math.sqrt

/*
    https://www.acmicpc.net/problem/2667
    2667번 단지번호붙이기
 */
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val n=readLine().toInt()
    val board=Array(n){readLine()}

    val visited = Array(n){Array(n){false}}
    var total=0
    val numbers= mutableListOf<Int>()
    fun dfs(x:Int, y:Int, c:Int=1) : Int{
        visited[x][y]=true
        var t=c
        for(i in 0 until 4){
            val nx=x+dx[i]
            val ny=y+dy[i]
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue
            if(visited[nx][ny] || board[nx][ny]=='0')continue
            t=max(t,dfs(nx,ny,t+1))
        }
        return t
    }
    for(i in 0 until n){
        for(j in 0 until n){
            if(!visited[i][j] && board[i][j]=='1'){//방문하지 않았을 때
                total++
                numbers.add(dfs(i,j))
            }
        }
    }
    
    numbers.sort()
    println(total)
    for(item in numbers){
        println(item)
    }
}
val dx=arrayOf(0,0,1,-1)
val dy=arrayOf(1,-1,0,0)

