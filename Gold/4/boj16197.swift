/*
 https://www.acmicpc.net/problem/16197
 16197번 두 동전
 백트래킹 가능
 4*4*4*4*4*4 * 4* 4 * 4 * 4
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

let inputs =  FastInput()
var n: Int = 0
var m: Int = 0
var board: [[Character]] = []
var res = Int.max
func input(){
    (n,m) = (inputs.readInt(),inputs.readInt())
    for _ in 0 ..< n{
        let temp = inputs.readString().map{$0}
        board.append(temp)
    }
}
struct loc{
    var x: Int
    var y: Int
}
func isOut(_ a: loc,_ b: loc) -> Int{
    var count = 0
    if a.x < 0 || a.x >= n || a.y < 0 || a.y >= m{count += 1}
    if b.x < 0 || b.x >= n || b.y < 0 || b.y >= m {count += 1}
    return count
}
let dx: [Int] = [0,0,1,-1]
let dy: [Int] = [1,-1,0,0]
func isWall(_ b: loc) -> Bool{
    return board[b.x][b.y] == "#"
}
func back(_ depth: Int,_ a: loc, _ b: loc){
    if depth == 10{
        return
    }
    for i in 0..<4{
        var nextA = loc(x: a.x + dx[i],y: a.y + dy[i])
        var nextB = loc(x: b.x + dx[i],y: b.y + dy[i])
        let ret = isOut(nextA,nextB)
        if ret == 1{
            res = min(res, depth + 1)
            return
        }else if ret == 2{continue}
        if isWall(nextA){
           nextA = a
        }
        if isWall(nextB){
            nextB = b
        }
        back(depth + 1,nextA,nextB)
    }
}
func solve(){
    var array: [loc] = []
    for i in 0..<n{
        for j in 0..<m{
            if board[i][j] == "o"{
                array.append(loc(x: i, y: j))
                board[i][j] = "."
            }
        }
    }
    back(0,array[0],array[1])
    print(res == Int.max ? -1 : res)
}

input()
solve()

