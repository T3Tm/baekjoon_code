import java.io.*
import java.util.*
import kotlin.math.max

/*
    https://www.acmicpc.net/problem/17281
    17281번 ⚾

    40320의 경우의수가 있다.
 */
val bw=BufferedWriter(OutputStreamWriter(System.out))
var score=0
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val game=Array(n){readLine().split(' ').map{it.toInt()}.toIntArray()}
    val result=Array(9){0}
    val avail= Array(9){false}
    avail[0]=true
    result[3]=0//4번째 주자는 1번타자이다.
    playBaseBall(n,result,game,avail)
    print(score)
}
fun playBaseBall(n:Int,result:Array<Int>,game:Array<IntArray>,avail:Array<Boolean>,depth:Int=0):Unit{
    if(depth==9){//다 정했으니 이것으로 게임 시작
        var lastidx=0//처음 시작은 0번째에 있는 타자
        var Point=0
        for(round in 0 until n){
            val base=Array(3){false}
            var zeroPoint=0
            while(zeroPoint!=3){
                when(game[round][result[lastidx]]){
                    0 -> zeroPoint++
                    1 -> {//모든 주자가 한 루씩
                        if(base[2])Point++
                        base[2]=base[1]
                        base[1]=base[0]
                        base[0]=true
                    }
                    2 ->{//모든 주자가 두 루씩
                        if(base[2])Point++
                        if(base[1])Point++
                        base[2]=base[0]
                        base[1]=true
                        base[0]=false
                    }
                    3 ->{//모든 주자가 세 루씩
                        if(base[2])Point++
                        if(base[1])Point++
                        if(base[0])Point++
                        base[2]=true
                        base[1]=false
                        base[0]=false
                    }
                    4 ->{//홈런
                        if(base[2])Point++
                        if(base[1])Point++
                        if(base[0])Point++
                        Point++
                        base[2]=false
                        base[1]=false
                        base[0]=false
                    }
                }
                lastidx=if(lastidx+1==9) 0 else lastidx+1
            }
        }
        score=max(score,Point)
        return
    }
    if(depth!=3){
        for(i in 0 until 9){
            if(!avail[i]){
                avail[i]=true
                result[depth]=i
                playBaseBall(n,result,game,avail,depth+1)
                result[depth]=0
                avail[i]=false
            }
        }
    }else {
        playBaseBall(n,result,game,avail,depth+1)
    }

}