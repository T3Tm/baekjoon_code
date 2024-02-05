import kotlin.system.exitProcess
/*
    https://www.acmicpc.net/problem/12101
    12101번 1, 2, 3 더하기 2
    [3] [3] [3] [3] [3] [3] [3] [3] [3] [3] [3] = 177147 경우의 수밖에 안 나옴
 */
val bw=System.out.bufferedWriter()
fun main() = java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    var k=r()
    fun `1, 2, 3`(result:Int=0,sb:StringBuilder = StringBuilder()){
        if(result==n){
            k--
            if(k==0){
                print(sb.toString())
                exitProcess(0)
            }
            return
        }
        (1..3).forEach{
            if(result+it<n){
                if(result!=0){
                    val nextsb=StringBuilder(sb).append('+').append(it)
                    `1, 2, 3`(result+it,nextsb)
                }else{
                    val nextsb=StringBuilder(sb).append(it)
                    `1, 2, 3`(it,nextsb)
                }
            }else if(result+it==n){
                if(result!=0){
                    val nextsb=StringBuilder(sb).append('+').append(it)
                    `1, 2, 3`(result+it,nextsb)
                }else{
                    val nextsb=StringBuilder(sb).append(it)
                    `1, 2, 3`(it,nextsb)
                }
            }
        }
    }
    `1, 2, 3`()
    print(-1)
}