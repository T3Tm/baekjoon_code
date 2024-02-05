import java.io.BufferedWriter
import java.io.OutputStreamWriter
import java.util.StringTokenizer

/*
    https://www.acmicpc.net/problem/6603
    6603번 로또
 */
val bw=BufferedWriter(OutputStreamWriter(System.out))
fun main() = with(System.`in`.bufferedReader()) {
    while(true){
        val st=StringTokenizer(readLine())
        val n=st.nextToken().toInt()
        val arr=IntArray(n)
        for(i in 0 until n)arr[i]=st.nextToken().toInt()
        if(n==0)break
        arr.sort()
        rotto(0,n,arr)
        bw.write("\n")
    }
    bw.flush()
}
fun rotto(depth:Int,n: Int,arr:IntArray,preidx:Int=-1,result:Array<Int> =Array(6){0}):Unit {
    if(depth==6){
        for(item in result){
            bw.write("$item ")
        }
        bw.write("\n")
        return
    }
    for(i in preidx+1 until n){
        result[depth]=arr[i]
        rotto(depth+1,n,arr,i,result)
    }
}

