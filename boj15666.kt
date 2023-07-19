val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val arr=readLine().split(' ').map{it.toInt()}.sorted().toIntArray()
    val result=Array(m){0}
    fun back(depth:Int=0,idx:Int = 0){
        if(depth==m){
            result.forEach {bw.write("$it ")}
            bw.write("\n")
            return
        }
        var last=-1
        (idx until n).forEach{
            if(last!=arr[it]){
                last=arr[it]
                result[depth]=last
                back(depth+1,it)
            }
        }
    }
    back()
    bw.flush()
}