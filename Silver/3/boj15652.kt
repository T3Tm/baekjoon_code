/*
    https://www.acmicpc.net/problem/15652
    15652번 N과 M (4)
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    back(n,m)
    bw.flush()
}
fun back(n:Int,m:Int,idx:Int=0,depth:Int=0,result:Array<Int> = Array(m){0}){
    if(depth==m){
        result.forEach {bw.write("$it ")}
        bw.write("\n")
        return
    }
    (idx until n).forEach{
        result[depth]=it+1
        back(n,m,it,depth+1,result)
    }
}

