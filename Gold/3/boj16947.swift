/*
 https://www.acmicpc.net/problem/16947
 16947번 서울 지하철 2호선
 dfs를 한 번 돌려서 사이클을 생기는 곳을 알아낸다.
 
 
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
var graph: [[Int]] = []
var result: [Int] = []
var visited: [Bool] = []
var cycle: [Bool] = []
func input(){
    n = inputs.readInt()
    graph = [[Int]](repeating: [], count: n+1)
    result = [Int](repeating: -1, count: n+1)
    visited = [Bool](repeating: false, count: n+1)
    cycle = visited
    for _ in 0..<n{
        let (a,b) = (inputs.readInt(),inputs.readInt())
        graph[a].append(b)
        graph[b].append(a)
    }
}
func dfs(_ x: Int, _ pre: Int) -> Bool{
    visited[x] = true
    var ret: Bool = false
    for next in graph[x]{
        if !visited[next]{// 현 시점에서는 무조건 못 찾았다고 해주기
            if ret{
                dfs(next, x) //갔던 곳이 true인지 알아내야 됨.
            }else{
                ret = dfs(next, x)
            }
        }else if (pre != next){//다음으로 가야되는 곳이 이미 방문한 적이 있고 그 점이 이전에 있던 점이 아니다? 그럼 무조건 사이클
            cycle[next] = true//미리 넣어놓기
            ret = true
        }
    }
    if cycle[x]{//내가 사이클의 시작 지점
        ret = false
    }else{
        cycle[x] = ret
    }
    return ret
}
func find(_ x: Int,_ depth: Int, _ pre: Int) -> Int{//가장 가까운 지점 찾읍시다~
    if cycle[x]{return depth}
    if result[x] != -1 {return result[x]}
    var ret = Int.max
    for next in graph[x]{
        if next != pre{
            ret = min(ret, find(next, depth + 1, x))
        }
    }
    return ret
}
func solve(){
    dfs(1, 0)//dfs한 번 돌려주기
    var res: String = ""
    for i in 1...n{//모든 정점에서 dfs 다시 돌려서 빠른 순환선 찾기
        let depth = find(i,0, 0)
        res += "\(depth) "
    }
    print(res)
}

input()
solve()

