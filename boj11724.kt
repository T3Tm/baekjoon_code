
/*
    https://www.acmicpc.net/problem/11724
    11724번 연결 요소의 개수
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val parent = IntArray(n){-1}
    repeat(m){
        val(u,v)=readLine().split(' ').map{it.toInt()}
        Union(u-1,v-1,parent)
    }
    var cnt=0
    repeat(n){
        if(parent[it]==-1)cnt++
    }
    print(cnt)
}
fun Union(a:Int,b:Int,pa:IntArray){
    var A=Find(a,pa)
    var B=Find(b,pa)
    if(A==B)return
    if(A<B){
        pa[B]=A
    }else{
        pa[A]=B
    }
}
fun Find(a:Int,pa:IntArray):Int{
    if(pa[a]==-1)return a//초기 상태
    pa[a]=Find(pa[a],pa)
    return pa[a]
}

