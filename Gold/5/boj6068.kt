import java.io.*
import java.util.*
import kotlin.math.*
/*
* https://www.acmicpc.net/problem/6068
* 6068번 시간 관리하기
*
* 1. 끝나는 시간을 기준으로 오름차순을 만든 뒤
  2. 시간을 뒤부터 보면서 끝시간, 현 시간을 갖고 더  작은 값을 갖고 가면서 일을 해야 되는 시간을 빼준다.
* */
fun main()= with(BufferedReader(InputStreamReader(System.`in`))){
    val n=readLine().toInt()
    var array = mutableListOf<Pair<Int,Int>>()
    var st:StringTokenizer?
    repeat(n){
        st=StringTokenizer(readLine())
        val T:Int=st!!.nextToken().toInt()
        val S:Int=st!!.nextToken().toInt()
        array.add(T to S)
    }
    array.sortBy { it.second }
    //끝나는 시간을 오름차순으로 만든다.
    var time=1000001
    for(i in n-1 downTo 0){
        time=min(time,array[i].second)
        time-=array[i].first
    }
    print(if(time <0)-1 else time)
}