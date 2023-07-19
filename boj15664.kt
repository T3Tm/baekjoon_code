/*
    https://www.acmicpc.net/problem/15664
    15664번 N과 M (10)
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val arr=readLine().split(' ').map{it.toInt()}.sorted().toIntArray()
    back(n,m,arr)
    bw.flush()
}
fun back(n:Int,m:Int,arr:IntArray,idx:Int = 0,depth:Int=0,result:Array<Int> = Array(m){0}){
    if(depth==m){
        result.forEach {bw.write("$it ")}
        bw.write("\n")
        return
    }
    val Avail=Array(10001){false}
    (idx until n).forEach{
        if(!Avail[arr[it]]){
            Avail[arr[it]]=true
            result[depth]=arr[it]
            back(n,m,arr,it+1,depth+1,result)
        }
    }
}