/*
    https://www.acmicpc.net/problem/2828
    2828번 사과 담기 게임
 */
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val m=r()
    val j=r()
    var left=1
    var right=m
    var count=0
    repeat(j){
        val x=r()//위치 입력
        if(left>x || x>right){//바구니의 위치를 벗어났네요
            if(left>x){// 바구니 왼쪽에 있음
                count+=left-x
                left=x
                right=x+m-1
            }else{//바구니 오른쪽에 있음
                count+=x-right
                right=x
                left=x-m+1
            }
        }
    }
    print(count)
}