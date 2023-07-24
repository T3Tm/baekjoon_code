import kotlin.math.max

/*
    https://www.acmicpc.net/problem/2504
    2504번 괄호의 값
 */
val bw=System.out.bufferedWriter()
fun main() =System.`in`.bufferedReader().run{
    val word=readLine()
    val s=mutableListOf<String>()
    var result=0
    for(item in word){
        when(item){
            '('->s.add(item+"")
            ')'->{//전에 나왔던 숫자들 다 더하기
                var temp=0
                while(s.isNotEmpty() && s.last()!="("){
                    if(s.last()=="["){
                        s.clear();break
                    }
                    temp+=s.removeLast().toInt()
                }
                temp*=2
                if(s.isEmpty() || s.last()!="("){
                    result=0
                    break
                }
                else{
                    s.removeLast()
                    temp=max(temp,2)
                    if(s.isEmpty())result+=temp
                    else s.add(temp.toString())
                }
            }
            '['->s.add(item+"")
            ']'->{
                var temp=0
                while(s.isNotEmpty() && s.last()!="["){
                    if(s.last()=="("){
                        s.clear();break
                    }
                    temp+=s.removeLast().toInt()
                }
                temp*=3
                if(s.isEmpty() || s.last()!="["){
                    result=0
                    break
                }
                else{
                    s.removeLast()
                    temp=max(temp,3)
                    if(s.isEmpty())result+=temp
                    else s.add(temp.toString())
                }
            }
        }
    }
    if(s.isNotEmpty())result=0
    print(result)
}