/*
    https://www.acmicpc.net/problem/15665
    15665번 N과 M (11)
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val arr=readLine().split(' ').map{it.toInt()}.sorted().toIntArray()
    val result=Array(m){0}
    fun back(depth:Int=0){
        if(depth==m){
            result.forEach {bw.write("$it ")}
            bw.write("\n")
            return
        }
        var last=-1
        repeat(n){
            if(last!=arr[it]){
                result[depth]=arr[it]
                last=arr[it]
                back(depth+1)
            }
        }
    }
    back()
    bw.flush()
}