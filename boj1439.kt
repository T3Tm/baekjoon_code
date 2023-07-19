/*
  https://www.acmicpc.net/problem/1439
  1439번 뒤집기
 */
fun main()=System.`in`.bufferedReader().run{
    val word=readLine().split('0')
    var zero=0
    var one=0
    var idx=0
    while(idx<word.size){
        if(word[idx] == "" || idx!=0)zero++
        while(idx<word.size && word[idx] == "")idx++;
        if(idx==word.size)break
        one++
        idx++
    }
    print(zero.coerceAtMost(one))
}