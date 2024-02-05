import kotlin.math.*
/*
    https://www.acmicpc.net/problem/15683
    15683번 감시
 */
data class CCTV(val i:Int, val j:Int, val c:Int, var dir:Int){}

val bw=System.out.bufferedWriter()
var board=mutableListOf<IntArray>()
var cctv=mutableListOf<CCTV>()
val directions= arrayOf(arrayOf(0),arrayOf(0,1,2,3),arrayOf(0,1),arrayOf(0,1,2,3),arrayOf(0,1,2,3),arrayOf(0))
var result=64
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    repeat(n){
        val t=readLine().split(' ').map{it.toInt()}.toIntArray()
        for((j,v) in t.withIndex()){
            if(v in 1..5)cctv.add(CCTV(it,j,v,-1))
        }
        board.add(t)
    }
    solve(n,m)
}
fun zeroCount(){
    val v=board.sumOf{row->row.count{it==0}}
    result=result.coerceAtMost(v)
}
fun cctvon(){
    //동,남,서,북으로 본다
    /*c==2 동, 동서,남북,서동,북남
      c==3 동남, 남서, 서북, 북동
      c==4 북동남, 동남서, 남서북, 서북동
      c==5 동서남북, 동서남북, 동서남북, 동서남북
    * */
    cctv.forEach {(i,j,c,dir)->
        when(c){
            1->diron(i,j,dir)
            2->{
                diron(i,j,dir)//0,1
                diron(i,j,(dir+2)%4)//2,3
            }
            3->{
                diron(i,j,dir)//0,1,2,3
                diron(i,j,(dir+1)%4)//1,2,3,0
            }
            4->{
                diron(i,j,(dir+3)%4)//3,0,1,2
                diron(i,j,dir)//0,1,2,3
                diron(i,j,(dir+1)%4)//1,2,3,0
            }
            5->{
                diron(i,j,0)
                diron(i,j,1)
                diron(i,j,2)
                diron(i,j,3)
            }
        }
    }
}
fun isboundary(x:Int,y:Int):Boolean{
    return x<0 || y<0 || x>=board.size || y>=board[0].size
}
val dx=arrayOf(0,1,0,-1)
val dy=arrayOf(1,0,-1,0)
fun diron(x:Int,y:Int,dir:Int){
    var nx=x+dx[dir]
    var ny=y+dy[dir]
    while(!isboundary(nx,ny) && board[nx][ny]!=6){
        board[nx][ny]=7
        nx += dx[dir]
        ny += dy[dir]
    }
}
fun dirMake(depth:Int = 0){
    if(depth == cctv.size){//모든 아이들의 방향을 정했음
        //board 만들기
        val temp= Array(board.size){board[it].copyOf()}
        cctvon()//cctv키기
        zeroCount()//0의 갯수 세기
        board = Array(temp.size){temp[it].copyOf()}.toMutableList()
        return
    }
    directions[cctv[depth].c].forEach{
        cctv[depth].dir=it
        dirMake(depth+1)
    }
}
fun solve(n:Int, m:Int):Unit{
    //방향 정하기
    dirMake()
    print(result)
}