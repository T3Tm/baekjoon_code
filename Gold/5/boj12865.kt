import kotlin.math.max

/*
  https://www.acmicpc.net/problem/12865
  12865번 평범한 배낭
  최대 K의 무게
 */
val bw=System.out.bufferedWriter()
data class bag(val w:Int,val v:Int):Comparable<bag>{
    override fun compareTo(o2: bag)= if(this.w!=o2.w)this.w-o2.w else this.v-o2.v
}
fun main()=java.io.StreamTokenizer(System.`in`.bufferedReader()).run{
    val r={nextToken();nval.toInt()}
    val n=r()
    val k=r()
    val dp = Array(100001){0}
    val bags=Array(n){val w=r();val v=r();bag(w,v)}
    bags.sort()
    for(i in bags.indices){
        val(w,v)=bags[i]
        for(value in k downTo 1){
            if(value-w>=1 && dp[value-w]!=0){//추가할 수 있다.
                dp[value]=max(dp[value],dp[value-w]+v)
            }else if(value-w==0){//하나만 이용해서 만들기
                dp[value]=max(dp[value],v)
            }
        }
    }
    print(dp.sliceArray(1..k).max())
}