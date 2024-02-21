/*
 https://www.acmicpc.net/problem/16954
 16954번 움직이는 미로 탈출
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

struct Queue{
    private var elements: [tuple] = [tuple](repeating: tuple(-1,-1,-1), count: 1000000)
    private var head: Int = 0
    private var tail: Int = 0
    var isEmpty: Bool{
        count == 0
    }
    var count: Int{
        tail - head
    }
    var front: tuple{
        elements[head]
    }
    var back: tuple{
        elements[tail]
    }
    mutating func push(_ element: tuple){
        elements[tail] = element
        tail += 1
    }
    mutating func pop() -> tuple{
        var ret: tuple = elements[head]
        head += 1
        return ret
    }
}
struct tuple: Equatable{
    var x: Int
    var y: Int
    var time: Int
    init(_ x: Int, _ y: Int, _ time: Int){
        self.x = x
        self.y = y
        self.time = time
    }
}
var q = Queue()
let inputs = FastInput()
var board: [[Character]] = []
let n: Int = 8
func input(){
    for _ in 0..<n{
        board.append(inputs.readString().map{$0})
    }
}
var loc: (Int, Int) = (7,0)
let end: (Int, Int) = (0,7)
var visited: [[[Bool]]] = [[[Bool]]](repeating: [[Bool]](repeating: [Bool](repeating: false, count: n+1), count: n+1), count: n+1)
let dx: [Int] = [0,0,1,1,1,-1,-1,-1,0]
let dy: [Int] = [1,-1,0,1,-1,0,1,-1,0]
func solve(){
    visited[loc.0][loc.1][0] = true
    q.push(tuple(loc.0,loc.1,0))
    var res = 0
    while !q.isEmpty{
        let f = q.pop()
        
        if (f.x,f.y) == end {
            res = 1
            break
        }
        for i in 0..<9{
            let next: tuple = tuple(f.x + dx[i],f.y + dy[i],(f.time + 1)%8)
            if next.x < 0 || next.x >= n || next.y < 0 || next.y >= n {continue}
            if next.x - f.time >= 0 && board[(next.x - f.time + 8) % 8][next.y] == "#" {continue}
            if next.x - f.time - 1 >= 0 && board[(next.x - f.time + 7) % 8][next.y] == "#" {continue}//한 칸 움직이면 움직일 수 없으니까 가지 말자.
            if visited[next.x][next.y][next.time] {continue}
            visited[next.x][next.y][next.time] = true
            q.push(next)
        }
    }
    print(res)
}

input()
solve()

