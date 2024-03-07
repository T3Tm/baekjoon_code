/*
 https://www.acmicpc.net/problem/23560
 23560번 약
 현재 며칠인지,
 day 1일이면 앞 먹어도 된다.
 day 2이면 점심이기에 점심 것을 먹어야 되기에
 day 3아침이든 점심 상관없음
 day 4 아침 점심 상관없음
 day 5 점심 것을 먹어야함
 front나 back이 점심인지 확인하고 먹기
 
 1,2,3
 4,5,6
 3*n+2이 해당되는지 확인
 front나 back이
 day%3 == 2 점심을 먹어야 한ㄷ.
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
var dp: [[Int]] = []
func input(){
    n=inputs.readInt()
    dp=[[Int]](repeating: [Int](repeating: -1, count: 3*n+1), count: 3*n+1)
}
func pill(_ day: Int,_ front: Int,_ back: Int)->Int{
    if back<front{//끝나는 순간
        return  1
    }
    if dp[front][back] != -1{
        return dp[front][back]
    }
    dp[front][back] = 0
    if day%3 == 2{//점심약을 먹을 차례
        if front%3 == 2{
            dp[front][back]+=pill(day+1,front+1,back)
        }
        if front != back && back%3 == 2{
            dp[front][back]+=pill(day+1,front,back-1)
        }
    }else{//아침 또는 저녁 약 먹기
        if front % 3 != 2{
            dp[front][back]+=pill(day+1,front+1,back)
        }
        if front != back && back % 3 != 2{
            dp[front][back]+=pill(day+1,front,back-1)
        }
    }
    return dp[front][back]
}
func solve(){
    print(pill(1, 1, 3*n))
}

input()
solve()

