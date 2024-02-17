/*
 https://www.acmicpc.net/problem/10868
 10868번 최솟값
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
var d: [[Int]] = []
var n: Int = 0
var m: Int = 0
func input(){
    (n,m) = (inputs.readInt(),inputs.readInt())
    d = [[Int]](repeating: [Int](repeating: 0, count: n+1), count: Int(log2(Double(n))) + 1)
}
func Precomputation(){
    for i in 1...n{
        d[0][i] = inputs.readInt()
    }
    // [i ~ i + 2^k) 구간 내에 최솟값 저장
    /// [i ~ i + 2^(k-1)] 의 2개으 구간에서 갖고온 최솟값을 저장
    for i in 1...Int(log2(Double(n))){//log2 행 동안
        for j in 1...(n - (1 << i) + 1){ //log번
            d[i][j] = min(d[i-1][j] , d[i-1][j + (1 << (i - 1))])
        }
    }
}
func solve(){
    Precomputation()
    // query를
    // 구간의 길이를 알아낸 다음
    // log 취해서 넣어주면 된다.
    // 3 ~ 5
    // 3,4,5 3개를 감싸야 하므로
    // 3,4 4,5 를 알아내면 된다.
    // let k = log2(Double(b - a + 1))
    //
    for _ in 0..<m{
        let (a,b) = (inputs.readInt(),inputs.readInt())
        let k = Int(log2(Double(b-a+1)))
        print(min(d[k][a], d[k][b - (1 << k) + 1]))
        //왼쪽 구간과 오른쪽 구간을 합쳐서 최소를 구하면 된다.
    }
}

input()
solve()

