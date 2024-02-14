/*
 https://www.acmicpc.net/problem/1305
 1305번 광고
 제일 작게 만들 수 있는 광고는
 1이고 제일 길게 만들 수 있는 광고는 사실상 L이다.
 */
var l: Int?
var word: [Character]?
func input(){
    l = Int(readLine()!)!
    word = readLine()!.map{$0}
}
func charToInt(_ idx: Int)->Int{
    return Int(word![idx].asciiValue!) - 96
}
func solve(){
    var lenArray: [Int] = [Int](repeating: 0, count: l!+1)
    var front: Int = 0
    var nowMaxLen: Int = 1
    lenArray[1] = charToInt(0)
    for idx in 1..<word!.count{
        let frontInt: Int = charToInt(front)
        let backInt: Int = charToInt(idx)
        lenArray[idx+1] = lenArray[idx] + charToInt(idx)
        if frontInt != backInt{//자른 것이 맞지 않는다..? 다시 잘라야 함.
            let preValue: Int = nowMaxLen
            nowMaxLen = idx + 1
            for value in preValue + 1..<nowMaxLen{// n번은 안 돈다.
                let nowFront = idx + 1 - value
                if lenArray[nowMaxLen] - lenArray[nowFront] == lenArray[value] && word![nowFront-1] == word![idx]{//반복이 돼서 가능하다는 것
                    nowMaxLen = value
                    break
                }
            }
            front = idx - nowMaxLen + 1
        }else{//같다면 front 땡겨서 크기 줄여주기!
            front += 1
        }
        
    }
    print(nowMaxLen)
}

input()
solve()
