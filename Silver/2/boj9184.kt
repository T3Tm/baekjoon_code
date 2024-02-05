/*
  https://www.acmicpc.net/problem/9184
  9184번 신나는 함수 실행
 */
val bw=System.out.bufferedWriter()
val memo=Array(103){Array(103){Array(103){-1L} } }
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    fun w(a:Int, b:Int, c:Int):Long{
        if(memo[a+50][b+50][c+50]!=-1L)return memo[a+50][b+50][c+50]

        memo[a+50][b+50][c+50]=0L
        if(a<=0 || b<=0 || c<=0){
            memo[a+50][b+50][c+50]=1L
        }
        else if(a > 20 || b > 20 || c > 20){
            memo[a+50][b+50][c+50]=w(20,20,20)
        }
        else if(b in (a + 1) until c){
            memo[a+50][b+50][c+50]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
        }
        else{
            memo[a+50][b+50][c+50]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
        }
        return memo[a+50][b+50][c+50]
    }
    while(true){
        val a=r()
        val b=r()
        val c=r()
        if(a==-1 && b==-1 && c==-1)break
        bw.write("w($a, $b, $c) = ${w(a,b,c)}\n")
    }
    bw.flush()
}