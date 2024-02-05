import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.math.max
/*
    https://www.acmicpc.net/problem/15662
    15662번 톱니바퀴 (2)
 */
val bw=System.out.bufferedWriter()
val dx=arrayOf(arrayOf(-1,6), arrayOf(1,2))
fun main() = System.`in`.bufferedReader().run{
    val wheels=mutableListOf<ArrayDeque<Char>>()
    val T=readLine().toInt()
    repeat(T){
        val t=ArrayDeque<Char>()
        readLine().toCharArray().forEach {
            t.addLast(it)
        }
        wheels.add(t)
    }

    fun Spinning(x:Int,dir:Int,visited:Array<Boolean> =Array(T){false}){
        visited[x]=true
        for(i in 0..1){
            val nx=x+dx[i][0]
            if(nx<0 || nx>=T)continue
            if(visited[nx])continue
            if(wheels[x][dx[i][1]]==wheels[nx][dx[(i+1)%2][1]])continue
            Spinning(nx,(dir+1)%2,visited)
        }
        when(dir){
            0->{
                val front = wheels[x].removeFirst()
                wheels[x].addLast(front)
            }
            1->{
                val back = wheels[x].removeLast()
                wheels[x].addFirst(back)
            }
        }
    }
    repeat(readLine().toInt()){
        val st=StringTokenizer(readLine())
        val num=st.nextToken().toInt()
        val dir=st.nextToken().toInt()
        Spinning(num-1,max(dir,0))
    }
    print(wheels.sumOf{it[0].code-'0'.code})
}