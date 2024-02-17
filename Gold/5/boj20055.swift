/*
 https://www.acmicpc.net/problem/20055
 20055번 컨베이어 벨트 위의 로봇
 
 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다. MoveContainer()
 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로
 한 칸 이동할 수 있는데, 이동 못 하면 가만히 있기 MoveRobot()
 2-1 이동하기 위해서는 로봇이 없어야 한다 + 내구도가 1이상
 3. 올리는 위치 (1) 에는 내구도가 0이 아니면 올린다.
    내구도 1이상이어야 한다.
 4. 0인칸이 k개 이상이면 과정을 종료한다. isContinue()
 일단 deque를 이용하면 너무 쉬울 것 같고
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

struct Deque{//50만
    private var elements: [Int] = [Int](repeating: 0, count: 500000)
    private var head: Int = 250000
    private var tail: Int = 250001
    var count: Int{
        tail - head - 1
    }
    var isEmpty: Bool{
        count == 0
    }
    var front: Int{
        elements[head]
    }
    var back: Int{
        elements[tail]
    }
    mutating func push_back(_ element: Int){
        elements[tail] = element
        tail += 1
    }
    mutating func push_front(_ element: Int){
        elements[head] = element
        head -= 1
    }
    mutating func pop_back() -> Int{
        tail -= 1
        let ret = elements[tail]
        return ret
    }
    mutating func pop_front() -> Int{
        head += 1
        let ret = elements[head]
        return ret
    }
    subscript(index: Int) -> Int {
        get {
            elements[head + index + 1]
        }
        set{
            elements[head + index + 1] = newValue
        }
    }
}
let inputs = FastInput()
var k: Int = 0//내구도 k개를 담당
var n: Int = 0
var kDeque = Deque() // 내구도 담당
var map = Deque()
func input(){
    (n,k) = (inputs.readInt(), inputs.readInt())
    let temp = inputs.readLine().split{$0 == " "}
    for t in temp{
        kDeque.push_back(Int(String(t))!)
        map.push_back(-1)//-1 아무도 없다는 것
    }
}
func MoveContainer(){
    map[n-2] = -1
    let t = map.pop_back()
    map.push_front(t)
    let q = kDeque.pop_back()
    kDeque.push_front(q)
}
func isContinue() -> Bool{
    var count: Int = 0
    for i in 0..<kDeque.count{
        if kDeque[i] <= 0{count += 1}
    }
    return count < k
}
func MoveRobot(){
    for i in stride(from: n - 2,to: -1,by: -1){//거꾸로 보면서
        if map[i] != -1{//누가 있음
            if map[i + 1] == -1{
                if kDeque[i + 1] >= 1{//이제 움직일 수 있음
                    kDeque[i+1] -= 1
                    map[i] = -1
                    map[i + 1] = 0//있다고 해주기
                    if i + 1 == n - 1 {
                        map[i+1] = -1
                    }
                }
            }
        }
    }
}
func LoadRobot(){//
    if kDeque[0] >= 1 {//내구도가 0이 아니므로 올릴 수 있음
        kDeque[0] -= 1
        map[0] = 0
    }
}
func solve(){
    var round: Int = 0
    repeat{
        MoveContainer()//이 때 로봇 내릴 수도 있으니까 확인 해야 됨.
        MoveRobot()
        LoadRobot()//로봇 올리기
        round += 1
    }while isContinue()
    print(round)
}

input()
solve()

