/*
  https://www.acmicpc.net/problem/9237
  9237번 이장님 초대
 */
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val arr=Array(n){r()}.sortedArray().reversedArray()
    var result=1
    for((idx,value)in arr.withIndex()){
        if(result>idx+value)continue//이미 건너띄기 했음
        result=result.coerceAtLeast(value+idx+1)
    }
    print(result+1)
}