import java.util.*
/*
    https://www.acmicpc.net/problem/16918
    16918번 봄버맨
 */
val bw=System.out.bufferedWriter()
val dx=arrayOf(0,0,1,-1,0)
val dy=arrayOf(1,-1,0,0,0)
fun main() = System.`in`.bufferedReader().run{
    val st=StringTokenizer(readLine())
    val r=st.nextToken().toInt()
    val c=st.nextToken().toInt()
    val n=st.nextToken().toInt()
    val boomTime=Array(r){Array(c){-1}}
    val board=Array(r){
        val temp=readLine()
        temp.forEachIndexed { j, c ->
            if(c=='O'){
                boomTime[it][j]=0//0초에 폭탄을 설치 했었음
            }
        }
        temp.toCharArray()
    }
    var time=1
    fun boomSet(){
        time++
        (0 until r).forEach{i->
            (0 until c).forEach{j->
                if(board[i][j]=='.'){
                    boomTime[i][j]=time//현재 시간 넣기
                    board[i][j]='O'//폭탄으로 바꾸기
                }
            }
        }
    }
    fun boom(){
        val query=mutableListOf<Pair<Int,Int>>()
        (0 until r).forEach{i->
            (0 until c).forEach{j->
                if(boomTime[i][j]+3==time){//3초 전에 설치된 폭탄들 삭제하기
                    query.add(Pair(i,j))//현재 시간 넣기
                }
            }
        }
        while(query.isNotEmpty()){
            val(x,y)=query.removeLast()
            for(i in 0.. 4){
                val nx=x+dx[i]
                val ny=y+dy[i]
                if(nx<0 || nx>=r || ny<0 || ny>=c)continue
                boomTime[nx][ny]=-1
                board[nx][ny]='.'
            }
        }
    }
    while(time<n){
        boomSet()
        if(time==n)break
        time++
        boom()
    }
    board.forEach {
        it.forEach {t-> bw.write("$t") }
        bw.write("\n")
    }
    bw.flush()
}