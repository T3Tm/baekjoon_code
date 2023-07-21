import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.math.max
/*
    https://www.acmicpc.net/problem/14891
    14891번 톱니바퀴
 */
val dx=arrayOf(arrayOf(-1,6), arrayOf(1,2))
const val number=4
fun main() = System.`in`.bufferedReader().run{
    val wheels=mutableListOf<ArrayDeque<Char>>()
    repeat(number){
        val t=ArrayDeque<Char>()
        readLine().toCharArray().forEach {
            t.addLast(it)
        }
        wheels.add(t)
    }

    fun Spinning(x:Int,dir:Int,visited:Array<Boolean> =Array(number){false}){
        visited[x]=true
        for(i in 0..1){
            val nx=x+dx[i][0]
            if(nx<0 || nx>=number)continue
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
    val mul= mutableListOf(1)
    repeat(number-1){
        mul.add(mul.last()*2)
    }

    var total=0
    repeat(number){
        total+=(wheels[it][0].code-'0'.code)*mul[it]
    }
    print(total)
}