import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.*
import java.util.*
import kotlin.math.*

/*
    https://www.acmicpc.net/problem/17406
    17406번 배열 돌리기 4
 */
data class tuple(val r:Int,val c:Int,val s:Int){}
val bw=BufferedWriter(OutputStreamWriter(System.out))
var value=5001
var minboard=Array(1){0}
var initboard=Array(1){0}
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m,k)=readLine().split(' ').map{it.toInt()}
    val board=Array(n){readLine().split(' ').map{it.toInt()}.toIntArray()}

    minboard=Array(n){0}
    initboard=Array(n){0}
    for(i in 0 until n){
        for(j in 0 until m){
            minboard[i]+=board[i][j]
        }
        initboard[i]+=minboard[i]
    }


    val query=mutableListOf<tuple>()
    repeat(k){
        val (r,c,s)=readLine().split(' ').map{it.toInt()}
        query.add(tuple(r-1,c-1,s))
    }
    choice(k,board,query)
    print(value)
}
fun arrcpy(dest:Array<Int>, src:Array<Int>){
    for((i,V) in src.withIndex()){
        dest[i]=V
    }
}
fun arrcpy(dest:Array<IntArray>, src:Array<IntArray>){
    for((i,V) in src.withIndex()){
        for((j,w) in V.withIndex()){
            dest[i][j]=w
        }
    }
}
fun choice(n:Int,board:Array<IntArray>,query:MutableList<tuple>,result:Array<Int> =Array(n){0},depth:Int =0,avail:Array<Boolean> = Array(n){false}){
    if(depth==n){
        val temp=Array(board.size){IntArray(board[0].size)}
        arrcpy(temp,board)
        for(item in result){
            val (r,c,s)=query[item]
            arrCircle(board,r,c,s)
        }

        for(item in minboard){
            value= min(value,item)
        }
        arrcpy(minboard,initboard)
        arrcpy(board,temp)
        return
    }
    for(i in 0 until n){
        if(!avail[i]){
            avail[i]=true
            result[depth]=i
            choice(n,board,query,result,depth+1,avail)
            avail[i]=false
        }
    }
}

fun arrCircle(board:Array<IntArray>,r:Int,c:Int,s:Int){
    val cnt=s
    var s_i=r-s
    var s_j=c-s
    var width=2*s
    repeat(cnt){//cnt 횟수만큼 배열 돌리기 반복해야됨
        var x=s_i
        var y=s_j//
        val save=board[x][y]
        minboard[x]+=save
        //왼쪽 열 땡겨주기
        repeat(width){
            minboard[x]-=board[x][y]
            board[x][y]=board[x+1][y]
            minboard[x]+=board[x][y]//이 값이 board에 더해줘야됨.
            x++
        }
        //아래 행 땡겨주기
        repeat(width){
            minboard[x]-=board[x][y]
            board[x][y]=board[x][y+1]
            minboard[x]+=board[x][y]//이 값이 board에 더해줘야됨.
            y++
        }
        //오른쪽 열 내려주기
        repeat(width){
            minboard[x]-=board[x][y]
            board[x][y]=board[x-1][y]
            minboard[x]+=board[x][y]//이 값이 board에 더해줘야됨.
            x--
        }
        //상단 행 오른쪽으로 움직이기
        repeat(width){
            minboard[x]-=board[x][y]
            board[x][y]=board[x][y-1]
            minboard[x]+=board[x][y]//이 값이 board에 더해줘야됨.
            y--
        }
        minboard[x]-=board[x][y]//값 빼야됨
        board[x][y+1]=save
        s_i++
        s_j++
        width-=2
    }
}
