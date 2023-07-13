import java.io.*
import java.math.BigInteger
import java.util.StringTokenizer
import kotlin.math.min
/*
* https://www.acmicpc.net/problem/2225
* 2225번 합분해
* 중복순열 문제
* a+b+c = N
* 0<=a,b,c<=N
* KHN
* k+n-1Cn
* 2+19C20
* 21C20
* 4+6-1C6
* 9C3
* */
val mod:BigInteger = BigInteger("${1e9.toInt()}")
fun main()= with(BufferedReader(InputStreamReader(System.`in`))){
    val st=StringTokenizer(readLine())
    var n=st.nextToken().toInt()
    val k=st.nextToken().toInt()+n-1
    n=min(n,k-n)
    var down:BigInteger= BigInteger("1")
    var up:BigInteger = BigInteger("1")
    for (i in 1..n){
        down*=i.toBigInteger()
    }
    for (i in k-n+1..k){
        up*=i.toBigInteger()
    }
    print((up/down).mod(mod))
}