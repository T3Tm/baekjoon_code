/*
 https://www.acmicpc.net/problem/1963
 1963번 소수 경로
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
var a: [Character] = []
var b: [Character] = []
var eratos: [Bool] = [Bool](repeating: true, count: 10002)
func input(){
    a = inputs.readString().map{$0}
    b = inputs.readString().map{$0}
}
func PreComputation(){
    eratos[0] = false
    eratos[1] = false
    for i in 2...Int(sqrt(Double(10002))){
        if !eratos[i]{continue}
        for j in stride(from: i*i,through: 10000, by:i){
            eratos[j] = false
        }
    }
}
func bfs() -> String{
    var q = Queue<[Character]>()
    q.push(a)
    var visited: [String : Int] = [:]
    visited[String(a)] = 0
    while !q.isEmpty{
        let f: [Character] = q.pop()
        if f == b{
            return String(visited[String(f)]!)
        }
        for i in 1...9{//0번 인덱스는 1~9
            var next = f
            next[0] = "\(i)".first!
            let n = String(next)
            if !eratos[Int(n)!] {continue}
            if (visited[n] ?? -1) != -1 {continue}
            visited[n] = visited[String(f)]! + 1
            q.push(next)
        }
        for j in 1..<4{//1번 3번 인덱스는 0부터 9까지
            for num in 0...9{
                var next = f
                next[j] = "\(num)".first!
                let n = String(next)
                if !eratos[Int(n)!] {continue}
                if (visited[n] ?? -1) != -1 {continue}
                visited[n] = visited[String(f)]! + 1
                q.push(next)
            }
        }
    }
    return "Impossible"
}
func solve(){
    let t = inputs.readInt()
    PreComputation()
    var res: String = ""
    for _ in 0..<t{
        input()
        res += "\(bfs())\n"
    }
    print(res)
}

solve()

