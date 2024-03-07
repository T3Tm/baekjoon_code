/*
 https://www.acmicpc.net/problem/22971
 22971번 증가하는 부분 수열의 개수
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
var arr: [Int] = []
var dp: [Int] = []
let mod: Int = 998244353
func input(){
    n = inputs.readInt()
    arr = [0]+inputs.readLine().split{$0 == " "}.map{Int(String($0))!}
    dp = [Int](repeating:0,count:n+1)
    
}
func solve(){
    for i in 1...n{
        var total=0
        for idx in 1...n{
            if arr[i]>arr[idx]{total = (total+dp[idx])%mod}
        }
        dp[i]=(total+1)%mod
    }
    var res = ""
    for i in 1...n{
        res.append("\(dp[i]) ")
    }
    print(res)
}

input()
solve()

