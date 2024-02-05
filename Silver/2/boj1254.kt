import com.sun.org.apache.xpath.internal.operations.Bool
import java.io.*
import java.util.*
/*
    https://www.acmicpc.net/problem/1254
    1254번 팰린드롬 만들기
    1. 지금 팰린드롬인지 확인
    뒤부터 시작해서 제일 중복되는 거
    12,27

 */
val bw=BufferedWriter(OutputStreamWriter(System.out))
fun main() = with(System.`in`.bufferedReader()) {
    val word=readLine()
    var flag=true
    for(left in word.indices){
        if(word.last() == word[left]){//이 부분부터 뒤에까지 겹치는지 확인
            if(palin(word,left)){//이 부분부터 팰린드롬이 되기에 나머지 뒤에 붙이면 됨.
                print(word.length+left)
                flag=false
                break
            }
        }
    }
}
fun palin(word:String,start:Int) : Boolean{
    for(left in 0..(word.length-start)/2){
        if(word[start+left]!=word[word.length-1-left]) return false
    }
    return true
}

