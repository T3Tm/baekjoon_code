import java.util.*
/*
   https://www.acmicpc.net/problem/1092
   1092번 배
   박스에 무거운 것부터 하나씩 차례대로 넣어놓고
   실어 보내기
 */
val bw=System.out.bufferedWriter()
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val readToken={nextToken();nval.toInt()}
    val n=readToken()
    val crane=Array(n){readToken()}.sortedArray().reversedArray()
    val m=readToken()
    var can=TreeSet<Int>()
    val boxes=Array(1000005){0}
    repeat(m){val x=readToken();can.add(x);boxes[x]++}
    var time=0
    out@while(!can.isEmpty()){
        time++
        for((idx,i) in crane.withIndex()){
            val value = can.floor(i)
            if(idx==0 && value==null){
                time=-1
                break@out
            }
            if (value != null) {
                boxes[value]--
                if(boxes[value]==0){
                    can.remove(value)
                }
            }
        }
    }
    print(time)
}