/*
 https://www.acmicpc.net/problem/14888
 14888번 연산자 끼워넣기
 
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
var numbers: [Int] = []
var op: [Int] = []
var mini = Int.max
var maxi = Int.min
func input(){
    n = inputs.readInt()
    numbers = inputs.readLine().split{$0 == " "}.map{Int(String($0))!}
    op = inputs.readLine().split{$0 == " "}.map{Int(String($0))!}
}
func back(_ depth: Int, _ number: Int){
    if depth == n - 1{//다 뽑음
        mini = min(mini,number)
        maxi = max(maxi,number)
        return
    }
    for i in 0..<4{
        if op[i] != 0 {
            op[i] -= 1
            var next = number
            switch i{
            case 0:
                next += numbers[depth + 1]
            case 1:
                next -= numbers[depth + 1]
            case 2:
                next *= numbers[depth + 1]
            case 3:
                if next < 0{
                    next = -((-next) / numbers[depth + 1])
                }else{
                    next /= numbers[depth + 1]
                }
            default:print()
            }
            back(depth + 1,next)
            op[i] += 1
        }
    }
}
func solve(){
    back(0,numbers[0])
    print(maxi)
    print(mini)
}

input()
solve()

