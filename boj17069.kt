/*
    https://www.acmicpc.net/problem/17070
    17069번 파이프 옮기기 (2)
 */
val bw=System.out.bufferedWriter()
fun main() =java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val arr=Array(n){Array(n){r()}}
    val dp=Array(n){Array(n){ LongArray(3){-1} }}
    val dx=arrayOf(0,1,1)
    val dy=arrayOf(1,1,0)
    val check= arrayOf(
        arrayOf(0 to 1),
        arrayOf(0 to 1, 1 to 1, 1 to 0),
        arrayOf(1 to 0)
    )
    fun boundary(dir:Int,x:Int,y:Int):Boolean{
        for((px,py)in check[dir]){
            if(arr[x+px][y+py]==1)return true
        }
        return false
    }
    val next=arrayOf(
        arrayOf(0,1),
        arrayOf(0,1,2),
        arrayOf(1,2)
    )
    fun dfs(x:Int,y:Int,dir:Int):Long{
        if(x==n-1 && y==n-1)return 1
        if(dp[x][y][dir]!=-1L)return dp[x][y][dir]
        dp[x][y][dir]=0
        for(i in next[dir]){
            val nx=x+dx[i]
            val ny=y+dy[i]
            if(nx>=n || ny>=n)continue
            if(boundary(i,x,y))continue
            dp[x][y][dir]+=dfs(nx,ny,i)
        }
        return dp[x][y][dir]
    }
    print(dfs(0,1,0))
}