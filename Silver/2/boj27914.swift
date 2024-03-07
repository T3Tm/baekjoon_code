/*
 https://www.acmicpc.net/problem/27914
 27914번 인터뷰
 1 0 1 2 0
 1,1,2,4,4
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
var n = 0
var k = 0
var q = 0
var arr: [Int] = []
var dp: [Int] = []
var prefix: [Int] = []
func input(){
    (n,k,q) = (inputs.readInt(),inputs.readInt(),inputs.readInt())
    arr=[0] + inputs.readLine().split{$0 == " "}.map{Int(String($0))!}
    dp = [Int](repeating: 0, count: n+1)
    prefix = dp
}
func solve(){
    for i in 1...n{
        prefix[i] = prefix[i-1] + dp[i]
        if arr[i] == k{continue}
        dp[i] = dp[i-1] + 1
        prefix[i] = prefix[i-1] + dp[i]
    }
    var res = ""
    for _ in 0..<q{
        let t = inputs.readInt()
        res.append("\(prefix[t])\n")
    }
    print(res)
}

input()
solve()

