data class room(val s:Int,val e:Int) : Comparable<room>{
    override fun compareTo(other:room)=if(other.e == this.e)this.s-other.s else this.e-other.e
}
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val n=readLine().toInt()
    val arr=Array(n){val(s,e)=readLine().split(' ').map{it.toInt()};room(s,e)}
    arr.sort()
    var cnt=1
    var (s,e)=arr[0]
    for(i in 1 until arr.size){
        if(e<=arr[i].s){
            cnt++
            s=arr[i].s
            e=arr[i].e
        }
    }
    print(cnt)
}