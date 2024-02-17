/*
 https://www.acmicpc.net/problem/20327
 20327번 배열 돌리기 6
 n*n의 행렬이 들어옴
 
 1. 상하 반전
 2. 좌우 반전
 3. 오른쪽 90도
 4. 왼쪽 90도 1,2,3,4는 부분배열을 바꾸는 것
 1,2,3,4는 첫 idx만 넘기고 경계면 체크만 하면 될 것 같다.
 5. 1번 플러스
 6. 2번 플러스
 7. 3번 플러스
 8. 4번 플러스
 5,6,7,8은 부분배열을 바꾸는 것이 아니라
 부분배열을 하나로 파악하고 돌리는 것
 새로운 2^k 배열로 생각을 하고 돌리면 될 듯
 해당하는 2^k의 구간을 각자 넣어주는 것으로 판단 내리면 될 것 같다.
 
 */
import Foundation

final class FastInput {
    private let bufferMaxSize: Int = 1 << 23
    private var buffer: [UInt8] = []
    private var bufferPointer: Int = 0

    init() { bufferPointer = bufferMaxSize }
    @inline(__always) private func _read() -> UInt8 {
        if bufferPointer == bufferMaxSize {
            buffer = [UInt8](FileHandle.standardInput.readData(ofLength: bufferMaxSize))
            bufferPointer = 0
        }
        if buffer[bufferPointer] == 0  { return 0 }
        defer { bufferPointer += 1 }
        return buffer[bufferPointer]
    }
    @inline(__always) func readInt() -> Int {
        var ret: Int = 0
        var minus: Bool = false
        var cur: UInt8 = _read()

        while cur == 10 || cur == 32 { cur = _read() }
        if cur == 45 {
            minus = true
            cur = _read()
        }
        while 48 <= cur, cur <= 57 {
            ret = ret * 10 + (Int)(cur - 48)
            cur = _read()
        }
        return ret * (minus ? -1 : 1)
    }
    @inline(__always) func readString() -> String {
        var ret: String = ""
        var cur: UInt8 = _read()
        while cur == 10 || cur == 32 { cur = _read() }
        while cur != 10, cur != 32, cur != 0 {
            ret.append(Character(UnicodeScalar(cur)))
            cur = _read()
        }
        return ret
    }
    @inline(__always) func readLine() -> String {
        var ret: String = ""
        var cur: UInt8 = _read()
        while cur == 10 { cur = _read() }
        while cur != 10, cur != 0 {
            ret.append(Character(UnicodeScalar(cur)))
            cur = _read()
        }
        return ret
    }
}

let inputs = FastInput()
var n = 0
var r = 0
var board: [[Int]] = []
func input(){
    (n,r) = (inputs.readInt(),inputs.readInt())
    let t = 1 << n
    for _ in 0..<t{
        let temp: [Int] = inputs.readLine().split{$0 == " "}.map{Int($0)!}
        board.append(temp)
    }
}
var alpha: Int = -1
var temp: [[Int]]  = []
func arrcpy(){
    board = temp//배열 복사!
}
func Up(_ x: Int, _ y: Int){//alpha 안에서 상하 반전
    //첫 행에 마지막부터 차근차근 넣어보자
    for i in x..<x+alpha{
        for j in y..<y+alpha{
            temp[i][j] = board[x + alpha - (i - x) - 1][j] //x+alpha - i - 1
        }
    }
}
func UpAndDown(){//alpha의 영역을 나눠서 코드를 짜면 되는데..시작해봅시다.
    //상하 반전인데 부분배열에서 상하 반전이다.
    // 0,0부터 시작하여서 2^alpha의 부분배열을 만들어야 한다.
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    for i in st{
        for j in st{//
            Up(i,j)
        }
    }
    arrcpy()
}
func Left(_ x: Int, _ y: Int){
    //첫 열에 마지막 열이 들어가면 된다.
    for j in y..<y+alpha{
        for i in x..<x+alpha{
            temp[i][j] = board[i][y + alpha - (j - y) - 1]
        }
    }
}
func LeftAndRight(){
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    for i in st{
        for j in st{//
            Left(i,j)
        }
    }
    arrcpy()
}
func Right(_ x: Int, _ y: Int){
    //왼쪽 열이 1행이 돼야 한다.
    for j in y..<y+alpha{ //
        for i in x..<x+alpha{// 2, 3
            temp[x + j - y][y + i - x] = board[x + alpha - (i - x) - 1][j]
        }
    }
}
func RightDegree(){//오른쪽으로 90도>
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    for i in st{
        for j in st{//
            Right(i,j)
        }
    }
    arrcpy()
}
func left(_ x: Int, _ y: Int){
    for j in y..<y+alpha{
        for i in x..<x+alpha{//마지막 열이 먼저 행으로 들어가야 한다.
            temp[x + j - y][y + i - x] = board[i][y + alpha - (j - y) - 1]
        }
    }
}
func LeftDegree(){
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    for i in st{
        for j in st{//
            left(i,j)
        }
    }
    arrcpy()
}
func up(_ x:Int, _ y: Int){
    //현재 x,y에 들어가야 되는 애들 바로 구해서 넣어주자.
    //2^2
    //2^3 - 2^1
    // 2^2
    // n / alpha << 4개가 나옴
    //
    let newN = (1 << n) / alpha
    for i in x..<x+alpha{
        for j in y..<y+alpha{
            temp[i][j] = board[(newN - (i / alpha) - 1) * alpha + (i - x)][j]
        }
    }
}
func NewUpAndDown(){//각각의 시작지점만 생각하고 돌려준다음에 배열로 복사해보자.
    // 상하 반전이라는 것이 x + alpha - i -1
    // 즉 첫 행에 마지막 행이 와야 된다는 것인데
    // 2^alpha개로 2^n을 자르면
    //상하 반전은 결국은 마지막행이 첫 행으로 가는데, 주의할 점이 어떤 값이 복사돼서 들어가는지를 알아야 된다.
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    // ((1 << alpha)  -  (i >> 1) - 1) // 몇 번째 블럭인지 나옴
    // 이 블럭이  어느 i,j인지 바로 나오면 됨
    // ((1 << alpha) * ((1 << alpha)  -  (i >> 1) - 1))
    // 완전히 끝
    for i in st{
        for j in st{
            //여기에 각각 상하 반전한 것들을 채워야 된다.
            up(i,j)
        }
    }
    arrcpy()
}
func newLeft(_ x: Int,_ y: Int){
    let newN = (1 << n) / alpha
    for j in y..<y+alpha{
        for i in x..<x+alpha{
            temp[i][j] = board[i][(newN - (j / alpha) - 1) * alpha + (j - y)]
        }
    }
}
func NewLeftAndRight(){
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    // ((1 << alpha)  -  (i >> 1) - 1) // 몇 번째 블럭인지 나옴
    // 이 블럭이  어느 i,j인지 바로 나오면 됨
    // ((1 << alpha) * ((1 << alpha)  -  (i >> 1) - 1))
    // 완전히 끝
    for i in st{
        for j in st{
            //여기에 각각 상하 반전한 것들을 채워야 된다.
            newLeft(i,j)
        }
    }
    arrcpy()
}
func right(_ x: Int,_ y: Int){
    //해당 칸의 첫 x,y를 구했음 마지막 x를 구해야됨.
    let newN = (1 << n) / alpha
    for j in y..<y+alpha{
        for i in x..<x+alpha{
            temp[x + j - y][y + i - x] = board[(newN - (j / alpha) - 1) * alpha + (j - y)][i]
        }
    }
}
func NewRightDegree(){
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    for i in st{
        for j in st{
            //여기에 각각 상하 반전한 것들을 채워야 된다.
            right(i,j)
        }
    }
    arrcpy()
}
func newleft(_ x: Int, _ y: Int){
    let newN = (1 << n) / alpha
    for j in y..<y+alpha{
        for i in x..<x+alpha{//마지막 열이 먼저 행으로 들어가야 한다.
            temp[x + j - y][y + i - x] = board[(j/alpha)*alpha + (j - y)][(newN - (i / alpha) - 1) * alpha + (i - x)]
        }
    }
}
func NewLeftDegree(){
    let st = stride(from: 0,to: 1 << n, by: alpha)//alpha만큼씩 커지면서 바꿔야 된다.
    for i in st{
        for j in st{
            //여기에 각각 상하 반전한 것들을 채워야 된다.
            newleft(i,j)
        }
    }
    arrcpy()
}
let command = [{()},UpAndDown,LeftAndRight,RightDegree,LeftDegree,NewUpAndDown,NewLeftAndRight,NewRightDegree,NewLeftDegree]

func arrayPrint(){
    var res: String = ""
    for i in 0..<(1 << n){
        for j in 0..<(1 << n){
            res += "\(board[i][j]) "
        }
        res += "\n"
    }
    
    print(res)
}
func solve(){
    temp = [[Int]](repeating: [Int](repeating:-1, count: (1 << n)), count: (1 << n))
    for _ in 0..<r{//커맨드 행동
        let (k,a) = (inputs.readInt(),inputs.readInt())
        alpha = 1 << a // 어떤 걸로 행동해야 되는지 알려주기
        command[k]() // 함수 실행하기
    }
    
    arrayPrint()
}

input()
solve()

