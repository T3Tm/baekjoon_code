/*
    https://www.acmicpc.net/problem/15656
    15656번 N과 M (7)
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val arr=readLine().split(' ').map{it.toInt()}.sorted().toIntArray()
    back(n,m,arr)
    bw.flush()
}
fun back(n:Int,m:Int,arr:IntArray,depth:Int=0,result:Array<Int> = Array(m){0}){
    if(depth==m){
        result.forEach {bw.write("$it ")}
        bw.write("\n")
        return
    }
    (0 until n).forEach{
        result[depth]=arr[it]
        back(n,m,arr,depth+1,result)
    }
}