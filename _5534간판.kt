import java.util.*
/*
https://www.acmicpc.net/problem/5534
간판
남은 문자가 모두 일정한 간격으로 떨어져 있어야 한다.
* */
fun main() = with(System.`in`.bufferedReader()){
    val n=readLine().toInt()
    val old=readLine()
    var cnt=0
    for(i in 1 .. n){//100개
        val olds=readLine()
        label@for((idx,c) in olds.withIndex()){
            if(c == old[0]) {
                for(j in 0..olds.length) {
                    if(match(idx, old, olds, j,0)){
                        cnt++
                        break@label
                    }
                }
            }
        }
    }
    print(cnt)
}
fun match(idx:Int ,a:String , b:String,step:Int ,preidx:Int) : Boolean{
    val value:Boolean
    if(preidx==a.length)return true
    else if(idx>=b.length)return false
    if(a[preidx]==b[idx]){
        value = match(idx+step,a,b,step,preidx+1)
    }else return false
    return value
}