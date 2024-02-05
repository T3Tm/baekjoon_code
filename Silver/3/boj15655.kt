/*
    https://www.acmicpc.net/problem/15655
    15655번 N과 M (6)
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val arr=readLine().split(' ').map{it.toInt()}.sorted().toIntArray()
    back(n,m,arr)
    bw.flush()
}
fun back(n:Int,m:Int,arr:IntArray,idx:Int=0,depth:Int=0,result:Array<Int> = Array(m){0}){
    if(depth==m){
        result.forEach {bw.write("$it ")}
        bw.write("\n")
        return
    }
    (idx until n).forEach{
        result[depth]=arr[it]
        back(n,m,arr,it+1,depth+1,result)
    }
}