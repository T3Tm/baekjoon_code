/*
 https://www.acmicpc.net/problem/16929
 16929번 Two Dots
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
var n: Int = 0
var m: Int = 0
var board: [[Character]] = []
var visited: [[Int]] = []
func input(){
    (n,m) = (inputs.readInt(),inputs.readInt())
    for _ in 0..<n{
        board.append(inputs.readString().map{$0})
    }
    visited = [[Int]](repeating: [Int](repeating: 0, count: m+2), count: n+2)
}
let dx: [Int] = [0,0,1,-1]
let dy: [Int] = [1,-1,0,0]
var res: Bool = false
func dfs(_ x: Int, _ y: Int, _ depth: Int, _ visitNum: Int, _ prex: Int, _ prey: Int){
    if res{return}
    visited[x][y] = visitNum
    for i in 0..<4{
        let nx = x + dx[i]
        let ny = y + dy[i]
        if (nx,ny) == (prex, prey){continue}//전에 왔던 좌표면 그냥 넘어가기
        if nx < 0 || nx >= n || ny < 0 || ny >= m {continue}
        if visited[nx][ny] != 0{//방문했으면 해당하는 곳이 나랑 같은 visitNum인지 확인
            if visited[nx][ny] == visitNum && depth >= 4{//가능
                res = true
            }
        }else if(board[nx][ny] == board[x][y]){//방문 안 했을 시 그냥 가기
            dfs(nx,ny,depth+1,visitNum,x,y)
        }
    }
}
func solve(){
    var num: Int = 1
EXIT:for i in 0..<n{
        for j in 0..<m{
            if res{break EXIT}
            if visited[i][j] != 0 {continue}
            dfs(i,j,1,num,-1,-1)
            num += 1
        }
    }
    print(res ? "Yes" : "No")
}

input()
solve()

