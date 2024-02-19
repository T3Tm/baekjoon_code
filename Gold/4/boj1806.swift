/*
 https://www.acmicpc.net/problem/1806
 1806번 부분합
 
 10000 이하의 자연수로 이루어진 길이 N짜리 수열이 주어지는데, 투포인터 이용하면 된다.
 */import Foundation
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
var s: Int = 0
var arr: [Int] = []
func input(){
    (n,s) = (inputs.readInt(),inputs.readInt())
    arr = inputs.readLine().split{$0 == " "}.map{Int(String($0))!}
}
func solve(){
    var res = Int.max
    var left = 0
    var right = 0
    var sum = 0
    while true{
        if sum <= s{
            if right >= n{break}
            if sum == s{res = min(res, right - left)}
            sum += arr[right]
            right += 1
        }else {
            res = min(res, right - left)
            sum -= arr[left]
            left += 1
        }
        if left > right{swap(&left,&right)}
    }
    if sum >= s{res = min(res, right - left)}
    print(res == Int.max ? 0 : res)
}

input()
solve()

