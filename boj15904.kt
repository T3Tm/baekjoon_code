/*
   https://www.acmicpc.net/problem/15904
   15904번 UCPC는 무엇의 약자일까?
 */
fun main()=with(System.`in`.bufferedReader()){
    val find=arrayOf('U','C','P','C')
    var idx=0
    for(i in readLine()){
        if(idx==4)break
        if(i == find[idx]){
            idx++
        }
    }
    print(if(idx==4)"I love UCPC" else "I hate UCPC")
}