/*
    https://www.acmicpc.net/problem/2167
    2167번 2차원 배열의 합


 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val m=r()
    val arr=Array(n+2){Array(m+2){0}}
    for(i in 1..n){
        for(j in 1..m){
            arr[i][j]=r()+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1]
        }
    }

    repeat(r()){
        val i=r()
        val j=r()
        val x=r()
        val y=r()
        bw.write("${arr[x][y]-arr[x][j-1]-arr[i-1][y]+arr[i-1][j-1]}\n")
    }
    bw.flush()

}