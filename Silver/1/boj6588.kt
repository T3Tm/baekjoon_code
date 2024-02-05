import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import kotlin.math.sqrt

/*
    https://www.acmicpc.net/problem/6588
    6588번 골드바흐의 추측
 */
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val prime=Array(1000002){true}
    prime[0]=false
    prime[1]=false
    for(i in 2..sqrt(1000000f).toInt()) {
        if (prime[i])
            for (j in i * i..1000000 step i) {
                prime[j] = false
            }
    }
    val bw=BufferedWriter(OutputStreamWriter(System.out))
    while(true){
        val n=readLine().toInt()
        if(n==0)break
        var flag=true
        for(i in 3..n/2 step 2){
            if(prime[i] && prime[n-i]){
                bw.write("$n = $i + ${n-i}\n")
                flag=false
                break
            }
        }
        if(flag){
            bw.write("Goldbach's conjecture is wrong.\n")
        }
    }
    bw.flush()
}