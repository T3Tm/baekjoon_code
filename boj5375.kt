import java.util.StringTokenizer

/*
    https://www.acmicpc.net/problem/5373
    5373번 큐빙

    U = 흰색 0
    D = 노란색 1
    F = 빨간색 2
    B = 주황색 3
    L = 초록색 4
    R = 파란색 5

    1. 큐브의 초기 상태를 만든다.
    2. 순서대로 spinning 한다.
    3. 윗면을 출력해준다.


    1. -으로 돌리면 반시계
    0 : 3(위쪽 행) -> 4(위쪽 행) -> 2(위쪽 행) -> 5(위쪽 행) 순서
    1 : 3(아래 행) -> 5(아래 행) -> 2(아래 행) -> 4(아래 행) 순서
    2 : 0(아래 행) -> 4(오른쪽 열) -> 1(아래 행) -> 5(왼쪽 열) 순서
    3 : 0(위쪽 행) -> 5(오른쪽 열) -> 1(위쪽 행) -> 4(왼쪽 열) 순서
    4 : 0(왼쪽 열) -> 3(오른쪽 열) -> 1(오른쪽 열) -> 2(왼쪽 열) 순서
    5 : 0(오른쪽 열) -> 2(오른쪽 열) -> 1(왼쪽 열) -> 3(왼쪽 열) 순서


    1. 자신을 저장하고
    2. 저장한 것을 다시 복사해서 넣어주면 된다.
    어차피 3개만 복사하면 된다.


    중간을 돌렸을 때
    왼쪽 열 -> 왼쪽 열 -> 오른쪽 열 -> 오른쪽 열
    2. + 시계 모양
    0 : 3 -> 5 -> 2 -> 4 순서
    1 : 3 -> 4 -> 2 -> 5 순서
    2 : 0 -> 5 -> 1 -> 4 순서
    3 : 0 -> 4 -> 1 -> 5 순서
    4 : 0 -> 2 -> 1 -> 3 순서
    5 : 0 -> 3 -> 1 -> 2 순서

    to (0 to 0)
    위,왼 : 0
    오른쪽,아래 : 1
    행 : 0
    열 : 1
    to(1 to 0)
    넘어갈 때 reverse 해야하는 것들도 생각해서 넘어가야함.

    주황색, 초록색 <-> 하얀색 reverse해야함
    빨간색, 초록색 <-> 노란색 reverse해야함
 */
val bw=System.out.bufferedWriter()
val reverseTrans=mapOf((2 to 1) to true,
    (1 to 2) to true,
    (4 to 1)to true,
    (1 to 4)to true,
    (3 to 0)to true,
    (0 to 3)to true,
    (4 to 0)to true,
    (0 to 4)to true)
typealias int=Int
//반시계 기준이다.
val CounterColck=arrayOf(
    arrayOf(3 to(0 to 0),4 to(0 to 0),2 to(0 to 0),5 to(0 to 0)),
    arrayOf(3 to(1 to 0),5 to(1 to 0),2 to(1 to 0),4 to(1 to 0)),
    arrayOf(0 to(1 to 0),4 to(1 to 1),1 to(1 to 0),5 to (0 to 1)),
    arrayOf(0 to (0 to 0),5 to (1 to 1),1 to (0 to 0),4 to (0 to 1)),
    arrayOf(0 to (0 to 1),3 to (1 to 1),1 to (1 to 1),2 to (0 to 1)),
    arrayOf(0 to (1 to 1),2 to (1 to 1),1 to (0 to 1),3 to (0 to 1)))
//시계 기준이다.
val Colck=arrayOf(
    arrayOf(3 to(0 to 0),5 to(0 to 0),2 to(0 to 0),4 to(0 to 0)),
    arrayOf(3 to(1 to 0),4 to(1 to 0),2 to(1 to 0),5 to(1 to 0)),
    arrayOf(0 to(1 to 0),5 to (0 to 1),1 to(1 to 0),4 to(1 to 1)),
    arrayOf(0 to (0 to 0),4 to (0 to 1),1 to (0 to 0),5 to (1 to 1)),
    arrayOf(0 to (0 to 1),2 to (0 to 1),1 to (1 to 1),3 to (1 to 1)),
    arrayOf(0 to (1 to 1),3 to (0 to 1),1 to (0 to 1),2 to (1 to 1)))

val trans=mapOf('U' to 0,'D' to 1,'F' to 2,'B' to 3, 'L' to 4,'R' to 5)
fun main() =System.`in`.bufferedReader().run{
    repeat(readLine().toInt()){
        val cube = init()
        val n=readLine().toInt()
        val st=StringTokenizer(readLine())
        repeat(n){
            Spinning(st.nextToken().toString(),cube)
        }
        cube[0].forEach{
            it.forEach {v->bw.write("$v")}
            bw.write("\n")
        }
    }
    bw.flush()
}
fun init(): MutableList<MutableList<CharArray>> {
    val ret = mutableListOf<MutableList<CharArray>>()
    ret.add(makeCube("w"))
    ret.add(makeCube("y"))
    ret.add(makeCube("r"))
    ret.add(makeCube("o"))
    ret.add(makeCube("g"))
    ret.add(makeCube("b"))
    return ret
}
fun makeCube(color:String):MutableList<CharArray>{
    val temps = mutableListOf<CharArray>()
    repeat(3){
        val temp = color.repeat(3).toCharArray()
        temps.add(temp)
    }
    return temps
}
fun Spinning(cmd: String,cube: MutableList<MutableList<CharArray>>) {
    val see=cmd[0]// U D F B L R
    val dir=cmd[1]//+ , -
    var temp:Array<Pair<Int, Pair<Int, Int>>> = arrayOf(1 to (1 to 1))
    when(dir){
        '+'->{
            temp = Colck[trans[see]!!]
            val num = trans[see]!!
            val total=mutableListOf<CharArray>()
            total.add(cube[num][2].copyOf())
            total.add(cube[num][1].copyOf())
            total.add(cube[num][0].copyOf())
            for(j in 2 downTo 0){
                repeat(3){i->
                    cube[num][i][j]=total[j][i]
                }
            }
        }
        '-'->{
            temp = CounterColck[trans[see]!!]
            val num = trans[see]!!
            val total=mutableListOf<List<Char>>()
            total.add(cube[num][0].copyOf().reversed())
            total.add(cube[num][1].copyOf().reversed())
            total.add(cube[num][2].copyOf().reversed())
            repeat(3){j->
                repeat(3){i->
                    cube[num][i][j]=total[j][i]
                }
            }
        }
    }
    val tempArray=CharArray(3)
    Arraycopy(tempArray,cube,temp.last())
    var preNumber=temp.last().first
    for((idx,Prepair) in temp.withIndex()){
        if(reverseTrans.getOrDefault(preNumber to Prepair.first,false))tempArray.reverse()
        ArrayCopy(tempArray,cube,Prepair)
        preNumber=Prepair.first
    }
}
fun ArrayCopy(tempArray:CharArray,cube:MutableList<MutableList<CharArray>>,temp:Pair<int,Pair<int,int>>){
    val (num,pair)=temp
    val TempArray=CharArray(3)
    Arraycopy(TempArray,cube,temp)
    when(pair.second) {//위,왼 : 0 , 오른쪽, 아래
        0 -> {//행
            when (pair.first) {
                0 -> {//위쪽 행
                    cube[num][0]=tempArray.copyOf()
                }

                1 -> {//아래 행
                    cube[num][2]=tempArray.copyOf()
                }
            }
        }

        1 -> {//열
            when (pair.first) {
                0 -> {//왼쪽 열
                    repeat(3) {
                        cube[num][it][0]=tempArray[it]
                    }
                }

                1 -> {//오른쪽 열
                    repeat(3) {
                        cube[num][it][2]=tempArray[it]
                    }
                }
            }
        }
    }
    repeat(3){tempArray[it]=TempArray[it]}
}
fun Arraycopy(tempArray: CharArray,cube:MutableList<MutableList<CharArray>>,temp:Pair<int,Pair<int,int>>) {
    val (num,pair)=temp
    when(pair.second) {//위,왼 : 0 , 오른쪽, 아래
        0 -> {//행
            when (pair.first) {
                0 -> {//위쪽 행
                    cube[num][0].forEachIndexed { idx, value -> tempArray[idx] = value }
                }

                1 -> {//아래 행
                    cube[num][2].forEachIndexed { idx, value -> tempArray[idx] = value }
                }
            }
        }

        1 -> {//열
            when (pair.first) {
                0 -> {//왼쪽 열
                    repeat(3) {
                        tempArray[it] = cube[num][it][0]
                    }
                }

                1 -> {//오른쪽 열
                    repeat(3) {
                        tempArray[it] = cube[num][it][2]
                    }
                }
            }
        }
    }
}
