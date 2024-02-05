/*
    https://www.acmicpc.net/problem/7795
    7795번 먹을 것인가 먹힐 것인가
    two pointer
 */
val bw=System.out.bufferedWriter()
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    repeat(r()){
        val a_size=r()
        val b_size=r()
        val A=Array(a_size){r()}.sorted()
        val B=Array(b_size){r()}.sorted()
        var idx=0
        var result=0
        for(item in A){
            for(i in idx until b_size){
                if(item<=B[i])break
                idx++
            }
            result+=idx
        }
        bw.write("${result}\n")
    }
    bw.flush()
}

/*
    https://www.acmicpc.net/problem/7795
    7795번 먹을 것인가 먹힐 것인가
    binarySerach
 */
val bw=System.out.bufferedWriter()
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    repeat(r()){
        val a_size=r()
        val b_size=r()
        val A=Array(a_size){r()}.sorted()
        val B=Array(b_size){r()}.sorted()
        var result=0
        for(item in A){
            val idx=binarySerach(item,B)
            result+=idx
        }
        bw.write("${result}\n")
    }
    bw.flush()
}
fun binarySerach(value:Int,arr:List<Int>):Int{
    var left=0
    var right=arr.size-1
    var ret=-1
    while(left<=right){
        val mid=(left+right)/2
        if(arr[mid]<value){
            ret=mid
            left=mid+1
        }else{
            right=mid-1
        }
    }
    return ret+1
}