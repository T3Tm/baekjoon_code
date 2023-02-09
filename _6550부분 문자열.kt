import java.util.StringTokenizer

/*
https://www.acmicpc.net/problem/6550
6550 부분 문자열
abc aabbcc
이렇게 있을 때
앞에 있는 것이 뒤에 있는지 확인

* */
fun main()= with(System.`in`.bufferedReader()){//
    for(i in readLines()){
        val st=StringTokenizer(i)
        var s=st.nextToken()
        var t=st.nextToken()
        println(subsequenceCheck(s,t))
    }
}
fun subsequenceCheck(result : String, base: String) : String{
    var idx=0
    for(value in base){
        if(result[idx]==value){
            idx++
        }
        if(idx == result.length)return "Yes"
    }
    return "No"
}