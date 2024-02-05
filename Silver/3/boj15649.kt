/*
    https://www.acmicpc.net/problem/15649
    15649번 N과 M (1)
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    back(n,m)
    bw.flush()
}
fun back(n:Int,m:Int,depth:Int=0,result:Array<Int> = Array(m){0},avail:Array<Boolean> = Array(n+1){false}){
    if(depth==m){
        result.forEach {bw.write("$it ")}
        bw.write("\n")
        return
    }
    (0 until n).forEach{
        if(!avail[it]){
            avail[it]=true
            result[depth]=it+1
            back(n,m,depth+1,result,avail)
            avail[it]=false
        }
    }
}