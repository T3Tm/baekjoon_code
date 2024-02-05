/*
    https://www.acmicpc.net/problem/2503
    2503번 숫자 야구

    123 1 1
    352 1 1
    504
 */
val bw=System.out.bufferedWriter()
data class my(val rep:Int,val s:Int,val b:Int){}
fun main() = with(System.`in`.bufferedReader()) {
    val n = readLine().toInt()
    val rem= mutableSetOf<my>()
    repeat(n){
        val(rep,s,b)=readLine().split(' ').map{it.toInt()}
        rem.add(my(rep,s,b))
    }
    var result=0
    for(f in 1..9){
        for(s in 1..9){
            if(f==s)continue
            label@for(t in 1..9){
                if(f==t || s==t)continue
                val check = "$f$s$t"
                for(it in rem){
                    var(rep,st,b)=it
                    val temp="$rep"
                    for(i in check.indices){//같은 위치 같은 숫자 처리
                        if(temp[i]==check[i])st--
                    }
                    if(st!=0)continue@label

                    for(i in check.indices){
                        for(j in temp.indices){
                            if(i==j)continue
                            if(check[i]==temp[j])b--
                        }
                    }
                    if(b!=0)continue@label
                }
                result++
            }
        }
    }
    print(result)
}