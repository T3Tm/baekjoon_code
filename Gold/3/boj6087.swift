/*
 https://www.acmicpc.net/problem/6087
 6087번 레이저 통신
 각 포인트에서 더 낮은 것으로 다시 돌아갈 이유가 없음
 visited 배열을 int 값으로 설정 후 현재에서 꺾어서 갈 수 있는지 판단
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

struct Queue<T>{
    private var elements: [T?] = [T?](repeating: nil, count: 1000000)
    private var head: Int = 0
    private var tail: Int = 0
    var isEmpty: Bool{
        count == 0
    }
    var count: Int{
        tail - head
    }
    var front: T{
        elements[head]!
    }
    var back: T{
        elements[tail]!
    }
    mutating func push(_ element: T){
        elements[tail] = element
        tail += 1
    }
    mutating func pop() -> T{
        var ret: T = elements[head]!
        head += 1
        return ret
    }
}

let inputs = FastInput()
var n: Int = 0
var m: Int = 0
var board: [[Character]] = []
var visited: [[[Int]]] = []
func input(){
    (m,n) = (inputs.readInt(),inputs.readInt())
    for _ in 0..<n{
        board.append(inputs.readLine().map{$0})
    }
    visited = [[[Int]]](repeating: [[Int]](repeating: [Int](repeating: Int.max, count: 4), count: m+1), count: n+1)
}
struct loc: Equatable{
    var x: Int
    var y: Int
    var dir: Int
}
let dx: [Int] = [0,0,1,-1]
let dy: [Int] = [1,-1,0,0]// 0 -> 2,3  1 -> 2,3
// 2 -> 0,1
// 3 -> 0,1
func solve(){
    var q = Queue<loc>()
    var arr: [loc] = []
    for i in 0..<n{
        for j in 0..<m{
            if board[i][j] == "C"{
                arr.append(loc(x: i, y: j, dir: -1))
            }
        }
    }
    for i in 0..<4{
        let next: loc = loc(x: arr[0].x + dx[i],y: arr[0].y + dy[i], dir: i)
        if next.x < 0 || next.x >= n || next.y < 0 || next.y >= m {continue}
        if board[next.x][next.y] == "*" {continue}//못 감
        q.push(next)
        visited[next.x][next.y][next.dir] = 0
    }
    while !q.isEmpty{
        let f = q.pop()
        let nextdir = [f.dir] + (f.dir>=2 ? [0,1] : [2,3])
        for z in nextdir{
            let next = loc(x: f.x + dx[z],y: f.y + dy[z], dir: z)
            let plus = (f.dir == next.dir ? 0 : 1)
            if next.x < 0 || next.x >= n || next.y < 0 || next.y >= m {continue}
            if board[next.x][next.y] == "*" {continue}//못 감
            if visited[next.x][next.y][next.dir] <= visited[f.x][f.y][f.dir] + plus{//한 번 꺾어야 됨 이미 간 거 보다 크기 때문에 굳이 가지 않기
                continue}
            visited[next.x][next.y][next.dir] = visited[f.x][f.y][f.dir] + plus
            q.push(next)
        }
    }
    print(visited[arr[1].x][arr[1].y].min()!)
}

input()
solve()

