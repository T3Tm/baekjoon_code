import java.util.*
/*
    https://www.acmicpc.net/problem/2304
    2304번 창고 다각형
 */
data class store(var l:Int, var h:Int):Comparable<store>{
    override fun compareTo(other: store)=this.l-other.l
}
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val arr=Array(n){val l=r();val h=r();store(l,h)}.sorted()
    var last= LinkedList<store>()
    var result=0
    for((l,h) in arr){
        if(last.isNotEmpty() && last.first.h<=h){
            result+=last.first.h*(l-last.first.l)
            last.clear()
        }
        last.offer(store(l,h))
    }
    var t=store(last.last.l,last.last.h)
    last.removeLast()//마지막 것은 한 번빼기
    while(last.isNotEmpty()){
        if(t.h<=last.last.h){
            result+=t.h*(t.l-last.last.l)
            t=store(last.last.l,last.last.h)
        }
        last.removeLast()
    }
    result+=t.h
    print(result)
}