fun main() = System.`in`.bufferedReader().run{
    val n=readLine().toInt()
    print(Array(n) { readLine().toLong() }.sorted().mapIndexed { i,v->kotlin.math.abs(i+1-v) }.sumOf{ it })
}