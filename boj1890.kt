/*
    https://www.acmicpc.net/problem/1890
    1890번 점프
 */
val bw=System.out.bufferedWriter()
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val arr=Array(n){Array(n){r()}}
    val dp=Array(n){LongArray(n){-1} }
    fun dfs(x:Int,y:Int):Long{
        if(x==n-1 && y==n-1)return 1
        if(dp[x][y]!=-1L)return dp[x][y]
        dp[x][y]=0
        val dx=arrayOf(arr[x][y],0)
        val dy=arrayOf(0,arr[x][y])
        for(i in 0..1){
            val nx=x+dx[i]
            val ny=y+dy[i]
            if(nx>=n || ny>=n)continue
            dp[x][y]+=dfs(nx,ny)
        }
        return dp[x][y]
    }
    print(dfs(0,0))
}