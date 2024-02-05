import java.io.*
import java.util.*
import kotlin.math.*
/*
    https://www.acmicpc.net/problem/11508
    11508번 2+1 세일
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val n =readLine().toInt()
    val arr=Array(n){readLine().toInt()}.sorted().reversed()
    var idx=0
    var result=0
    repeat(arr.size/3){i->
        for(j in idx..idx+2){
            result+=if((j+1)%3==0) 0 else arr[j]
        }
        idx+=3
    }
    repeat(arr.size%3){
        result+=arr[idx++]
    }
    print(result)
}