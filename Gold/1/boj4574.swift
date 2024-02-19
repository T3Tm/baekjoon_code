/*
 https://www.acmicpc.net/problem/4574
 4574번 스도미노쿠
 
 0,0 0,1,0,2 0,3 0,4 0,5 0,6 0,7 0,8
 1,0,1,1,1,2 1,3 1,4 1,5 1,6 1,7 1,8
 2,0,2,1,2,2 2,3 2,4 2,5 2,6 2,7 2,8
 3,0 3,1 3,2
 4,0 4,1 4,2
 x/3 * 3 + y/3
 
 행과 열이 모두 3보다 작으면 0번이다.
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
var board: [[Int]] = []
var avail: [[Bool]] = []
var horizonal: [[Bool]] = []
var vertical: [[Bool]] = []
var square: [[Bool]] = []
var res: String = ""
var n: Int = 0
func TransLocation(_ x: String) -> (Int, Int){
    let X: Int = Int((x.first?.asciiValue)!) - 65
    let Y: Int = Int((x.last?.asciiValue)!) - 49
    return (X,Y)
}
func Spend(_ loc:(Int, Int), _ num: Int){
    horizonal[loc.0][num] = false
    vertical[loc.1][num] = false
    square[loc.0 / 3 * 3 + loc.1/3][num] = false
    board[loc.0][loc.1] = num
}
func UnSpend(_ loc:(Int, Int), _ num: Int){
    horizonal[loc.0][num] = true
    vertical[loc.1][num] = true
    square[loc.0 / 3 * 3 + loc.1/3][num] = true
    board[loc.0][loc.1] = 0
}
func input() -> Bool{
    n = inputs.readInt()
    if n == 0{return false}
    avail = [[Bool]](repeating: [Bool](repeating: true, count: 10), count: 10)
    board = [[Int]](repeating: [Int](repeating: 0, count: 9), count: 9)
    horizonal = [[Bool]](repeating: [Bool](repeating: true, count: 10), count: 9)
    vertical  = [[Bool]](repeating: [Bool](repeating: true, count: 10), count: 9)
    square = [[Bool]](repeating: [Bool](repeating: true, count: 10), count: 9)
    for _ in 0..<n{
        let temp = inputs.readLine().split{$0 == " "}
        let first = Int(temp[0])!
        let (x,y) = TransLocation(String(temp[1]))
        let second = Int(temp[2])!
        let (X,Y) = TransLocation(String(temp[3]))
        avail[min(first,second)][max(second,first)] = false
        //이미 놓였으니 사용하면 안 됨
        Spend((x,y), first)
        Spend((X,Y), second)
    }
    for i in 1...9{
        let t = inputs.readString()
        let (x,y) = TransLocation(t)
        Spend((x,y), i)
    }
    return true
}
func isSquare(_ x: Int, _ y: Int, _ number: Int) -> Bool{
    return square[x/3 * 3 + y/3][number]
}
func isHorizonal(_ x: Int, _ number: Int) -> Bool{
    return horizonal[x][number]
}
func isVertical(_ y: Int, _ number: Int) -> Bool{
    return vertical[y][number]
}
func printBoard(){
    var res: String = ""
    for i in 0..<9{
        for j in 0..<9{
            res += "\(board[i][j])"
        }
        res += "\n"
    }
    print(res)
}
func back(_ loc:(Int, Int)) -> Bool{
    if loc.0 == 9 && loc.1 == 0{//36개를 다 선택했음
        for i in 0..<9{
            for j in 0..<9{
                res += "\(board[i][j])"
            }
            res += "\n"
        }
        return true
    }
    var ret: Bool = false
    if board[loc.0][loc.1] != 0{
        if loc.1 + 1 != 9 {
            ret = back((loc.0,loc.1+1))
        }else{
            ret = back((loc.0 + 1,0))
        }
        if ret {return true}
    }
    else if board[loc.0][loc.1] == 0{//이렇게 됐을 때
        if (loc.0 + 1 >= 9 || board[loc.0+1][loc.1] != 0) && (loc.1 + 1 >= 9 || board[loc.0][loc.1+1] != 0) {
            return false
        }
        if loc.0+1 < 9 && board[loc.0+1][loc.1] == 0 {//아래를 볼 수 있을 때
            for num1 in 1..<9{
                if !isHorizonal(loc.0, num1){continue}
                if !isVertical(loc.1, num1){continue}
                if !isSquare(loc.0,loc.1, num1){continue}
                Spend((loc.0,loc.1), num1)
                for num2 in num1...9{
                    if !avail[num1][num2]{continue}
                    if !isHorizonal(loc.0 + 1, num2){continue}
                    if !isVertical(loc.1, num2){continue}
                    if !isSquare(loc.0+1,loc.1, num2){continue}
                    Spend((loc.0+1,loc.1), num2)
                    avail[num1][num2]=false
                    if loc.1+1 != 9{
                        ret = back((loc.0,loc.1+1))
                    }else{
                        ret = back((loc.0 + 1,0))
                    }
                    if ret{return true}
                    UnSpend((loc.0+1,loc.1), num2)
                    avail[num1][num2]=true
                }
                UnSpend((loc.0,loc.1), num1)
            }
            
            
            for num1 in 1..<9{
                if !isHorizonal(loc.0+1, num1){continue}
                if !isVertical(loc.1, num1){continue}
                if !isSquare(loc.0+1,loc.1, num1){continue}
                Spend((loc.0+1,loc.1), num1)
                for num2 in num1...9{
                    if !avail[num1][num2]{continue}
                    if !isHorizonal(loc.0, num2){continue}
                    if !isVertical(loc.1, num2){continue}
                    if !isSquare(loc.0,loc.1, num2){continue}
                    Spend((loc.0,loc.1), num2)
                    avail[num1][num2]=false
                    if loc.1+1 != 9{
                        ret = back((loc.0,loc.1+1))
                    }else{
                        ret = back((loc.0 + 1,0))
                    }
                    if ret{return true}
                    UnSpend((loc.0,loc.1), num2)
                    avail[num1][num2]=true
                }
                UnSpend((loc.0+1,loc.1), num1)
            }
        }
        if loc.1+1 < 9 && board[loc.0][loc.1+1] == 0 {//오른쪽 볼 수 있음
            for num1 in 1..<9{
                if !isHorizonal(loc.0, num1){continue}
                if !isVertical(loc.1, num1){continue}
                if !isSquare(loc.0,loc.1, num1){continue}
                Spend((loc.0,loc.1), num1)
                for num2 in num1...9{
                    if !avail[num1][num2] {continue}
                    if !isHorizonal(loc.0, num2){continue}
                    if !isVertical(loc.1+1, num2){continue}
                    if !isSquare(loc.0,loc.1+1, num2){continue}
                    Spend((loc.0,loc.1+1), num2)
                    avail[num1][num2]=false
                    if loc.1+2 != 9{
                        ret = back((loc.0,loc.1+2))
                    }else{
                        ret = back((loc.0 + 1,0))
                    }
                    if ret{return true}
                    UnSpend((loc.0,loc.1+1), num2)
                    avail[num1][num2]=true
                }
                UnSpend((loc.0,loc.1), num1)
            }
            
            
            for num1 in 1..<9{
                if !isHorizonal(loc.0, num1){continue}
                if !isVertical(loc.1+1, num1){continue}
                if !isSquare(loc.0,loc.1+1, num1){continue}
                Spend((loc.0,loc.1+1), num1)
                for num2 in num1...9{
                    if !avail[num1][num2]{continue}
                    if !isHorizonal(loc.0, num2){continue}
                    if !isVertical(loc.1, num2){continue}
                    if !isSquare(loc.0,loc.1, num2){continue}
                    Spend((loc.0,loc.1), num2)
                    avail[num1][num2]=false
                    if loc.1+2 != 9{
                        ret = back((loc.0,loc.1+2))
                    }else{
                        ret = back((loc.0 + 1,0))
                    }
                    if ret{return true}
                    UnSpend((loc.0,loc.1), num2)
                    avail[num1][num2]=true
                }
                UnSpend((loc.0,loc.1+1), num1)
            }
        }
    }
    return false
}
func solve(){
    var round: Int = 1
    while true{
        guard input() else{break}//입력 받았을 때만 가능
        res.append("Puzzle \(round)\n")
        back((0,0))//백트래킹 시작
        round += 1
    }
    print(res,terminator: "")
}
solve()

