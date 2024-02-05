import java.math.BigInteger
import java.util.StringTokenizer

/*
* https://www.acmicpc.net/problem/15489
* 15489 파스칼 삼각형
*   2<= R+W <= 30
    2<= C+W <= 30
    * 1<= W <= 29 이건 즉 한 변의 길이의 최대가 29, 즉 29의 줄을 다 더해야 됨.
    * C <= R 이건 당연한 거고
    *
    * 만약 W == 29 이면 C == 1  R도 1 이다.
    * 이랬을 때
    * 2차원 배열 31,31 만든다음
    * 왼쪽 오른쪽 이라는 게
    * 각 행의 0번과 (행-1)번에 1을 추가해야되네.
    * if (column == 0 || column == row-1) arr[column]= 1
    * 이런식으로 기술하면 될 듯
    * 1 0 0 0 0 0
    * 1 1 0 0 0 0
    * 1 2 1 0 0 0 이런식으로 채우면 되지 않을까? 여기도 왼쪽 오른쪽 하나씩
* */
fun main()= with(System.`in`.bufferedReader()){
    val st = StringTokenizer(readLine())
    var r= st.nextToken().toInt()-1
    var c= st.nextToken().toInt()-1
    var w=st.nextToken().toInt()-1
    var sum= BigInteger("0")
    var arr= Array(31){
        Array(31){0}
    }
    for(row in 0..30){
        for(column in 0..row){
            if(column == 0 || column == row)arr[row][column]=1
            else arr[row][column]=arr[row-1][column]+arr[row-1][column-1]
        }
    }
    for(i in r..r+w){
        for(j in c..c+(i-r)){
            sum+=arr[i][j].toBigInteger()
        }
    }
    print(sum)
}
