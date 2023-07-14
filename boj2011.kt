import java.io.BufferedReader
import java.io.InputStreamReader

/*
    https://www.acmicpc.net/problem/2011
    2011번 암호코드
    arr[i-1][0] 한자리씩 끊어서 읽었을 떄
    arr[i-1][1] 두자리씩 끊어서 읽었을 때
 */
const val MOD=1000000
fun main() = with(BufferedReader(InputStreamReader(System.`in`))){
    val word=readLine()//최대5000자리
    val dp=Array(word.length+1){0}
    if(word[0]!='0')dp[0]=1
    for(i in 1..word.length){
        if(word[i-1]!='0')dp[i]=dp[i-1]%MOD
        if(i>=2){
            if(word[i-2]=='1'){
                dp[i]=(dp[i]+dp[i-2])%MOD
            }else if(word[i-2]=='2'){
                if(word[i-1]!='7' && word[i-1]!='8' && word[i-1]!='9')dp[i]=(dp[i]+dp[i-2])%MOD
            }
        }
    }
    print(dp[word.length])
}