/*
 https://www.acmicpc.net/problem/16964
 16964번 DFS 스페셜 저지
 
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
var graph: [Set<Int>] = []
var visited: [Int] = []//부모를 저장
var arr: [Int] = [0]
var child: [Int] = []
func input(){
    n = inputs.readInt()
    graph = [Set<Int>](repeating: Set(), count: n+1)
    visited = [Int](repeating: -1, count: n+1)
    child = [Int](repeating: 0, count: n+1)
    for _ in 0..<n-1{
        let (a,b) = (inputs.readInt(),inputs.readInt())
        graph[a].insert(b)
        graph[b].insert(a)
    }
    arr.append(contentsOf: inputs.readLine().split{$0 == " "}.map{Int(String($0))!})
    graph[0].insert(1)
}
func dfs(_ x: Int, _ pre: Int){
    visited[x] = pre
    child[pre] += 1
    for next in graph[x]{
        if visited[next] != -1 {continue}
        dfs(next, x)
    }
}
var flag: Bool = false
var idx: Int = 0
var set: Set<Int> = Set()
func find(_ x: Int){
    if flag {return}
    if idx >= n {return}
    //보기 전에 내가 만약 돌아가야 된다면?
    //갈 수 있는 곳인데 x의 자식이 없다? 그러면
    set.insert(x)//돌았음
    if child[x] == 0 {//자식들을 다 돌았음
        find(visited[x])//내 부모를 넘겨줘서 맞는지 확인
    }
    //다음으로 보려는 숫자가 내가 갈 수 있는 곳이 아니면 return
    else if !graph[x].contains(arr[idx + 1]){
        flag = true
        return
    }else{//갈 수 있음 전에 안 갔던 곳으로 가야 된다.
        if set.contains(arr[idx + 1]){//왜 돌았던 거 또 가..?
            flag = true
            return
        }
        child[x] -= 1 //내가 갈 수 있는 자식을 하나씩 지우기
        idx += 1
        find(arr[idx])
    }
}
func solve(){
    dfs(0, 0)
    child[0] = 1
    //모든 아이들의 부모를 저장
    find(0)
    print(flag ? 0 : 1)
}

input()
solve()

