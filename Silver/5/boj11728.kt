import java.util.PriorityQueue

/*
    https://www.acmicpc.net/problem/11728
    11728번 배열 합치기
 */
val bw=System.out.bufferedWriter()
fun main() = with(System.`in`.bufferedReader()) {
    val(n,m)=readLine().split(' ').map{it.toInt()}
    val arr=readLine().split(' ').map{it.toInt()}.toIntArray()
    val arr1=readLine().split(' ').map{it.toInt()}.toIntArray()
    val result= mutableListOf<Int>()
    var left=0
    var right=0
    while(left<n && right <m){
        if(arr[left]<arr1[right]){
            result.add(arr[left++])
        }else{
            result.add(arr1[right++])
        }
    }
    while(left<n)result.add(arr[left++])
    while(right<m)result.add(arr1[right++])
    result.forEach{i->bw.write("$i ")}
    bw.flush()
}

