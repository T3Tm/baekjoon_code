import java.util.StringTokenizer
/*
    https://www.acmicpc.net/problem/10828
    10828번 스택
 */
val bw=System.out.bufferedWriter()
fun main() =System.`in`.bufferedReader().run{
    val s= mutableListOf<Int>()
    var st=StringTokenizer(readLine())
    val trans=mapOf(true to 1,false to 0)
    repeat(st.nextToken().toInt()){
        st=StringTokenizer(readLine())
        val cmd=st.nextToken().toString()
        when(cmd[0]){
            'p'->{
                if(cmd[1]=='o'){
                    bw.write("${s.removeLastOrNull()?:-1}\n")
                }else{
                    s.add(st.nextToken().toInt())
                }
            }
            't'->bw.write("${s.lastOrNull()?:-1}\n")
            's'->bw.write("${s.size}\n")
            'e'->bw.write("${trans[s.isEmpty()]}\n")
        }
    }
    bw.flush()
}