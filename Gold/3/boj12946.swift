/*
 https://www.acmicpc.net/problem/12946
 12946번 육각 보드
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
var board: [[Character]] = []
var visited: [[Int]] = []
func input(){
    n = inputs.readInt()
    visited = [[Int]](repeating: [Int](repeating: -1 , count: n+1), count: n+1)
    for _ in 0..<n{
        board.append(inputs.readString().map{$0})
    }
}
let dx: [Int] = [0,0,1,1,-1,-1]
let dy: [Int] = [1,-1,-1,0,0,1]
func dfs(_ loc: (Int, Int), _ pre: (Int, Int), _ num: Int){
    visited[loc.0][loc.1] = num
    let next = (num == 2 ? 1 : 2)
    for i in 0..<6{
        let nx = loc.0 + dx[i]
        let ny = loc.1 + dy[i]
        if nx < 0 || nx >= n || ny < 0 || ny >= n {continue}
        if board[nx][ny] == "-" {continue}
        if visited[nx][ny] == -1{
            dfs((nx,ny), loc, next)
        }else if visited[nx][ny] != next{//방문한 적이 있다면?
            visited[loc.0][loc.1] = 3
        }
    }
}
func solve(){
    for i in 0..<n{
        for j in 0..<n{
            if visited[i][j] != -1 {continue}
            if board[i][j] == "-" {continue}
            dfs((i,j) , (-1,-1),1)
        }
    }
    var res = 0
    for i in 0..<n{
        res = max(res,visited[i].max()!)
    }
    print(res)
}

input()
solve()

