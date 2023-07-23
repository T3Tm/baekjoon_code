/*
    https://www.acmicpc.net/problem/1080
    1080번 행렬

    101          010
    101          101
    101          101

 */
val bw=System.out.bufferedWriter()
fun main() =System.`in`.bufferedReader().run{
    val (n,m)=readLine().split(' ').map{it.toInt()}
    val A=Array(n){readLine().toCharArray().map{it.code-'0'.code}.toIntArray()}
    val B=Array(n){readLine().toCharArray().map{it.code-'0'.code}.toIntArray()}
    var count=0L
    fun flip(i:Int,j:Int){
        repeat(3){x->
            repeat(3){y->
                A[i+x][j+y]=(A[i+x][j+y]+1)%2
            }
        }
    }
    for(i in 0..n-3){
        for(j in 0..m-3){
            if(A[i][j]!=B[i][j]){//좌상단 다른지 확인
                flip(i,j)
                count++
            }
        }
    }
    fun check():Boolean{
        A.forEachIndexed {i,row->
            row.forEachIndexed {j,column->
                if(A[i][j]!=B[i][j])return false
            }
        }
        return true
    }
    print(if(check())count else -1)
}