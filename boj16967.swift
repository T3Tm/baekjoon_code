/*
 https://www.acmicpc.net/problem/16967
 16967번 배열 복원하기
 */
var h: Int?
var w: Int?
var x: Int?
var y: Int?
var res: [[Int]] = []
var B: [[Int]] = []
func input(){
    let t = readLine()!.split{$0 == " "}.map{Int(String($0))!}
    (h,w,x,y) = (t[0],t[1],t[2],t[3])
    for _ in 0 ..< h! + x! {
        B.append(readLine()!.split{$0 == " "}.map{Int(String($0))!})
    }
    res = B
}
func solve(){
    //1. x,y부터 시작해서 A에다가 어떻게 넣을지 확인
    for i in x!..<h!{
        for j in y!..<w!{
            res[i][j] -= res[i-x!][j-y!]
        }
    }
    //2. 그리고 출력
    var out: String = ""
    for i in 0..<h!{
        for j in 0..<w!{
            out.append("\(res[i][j]) ")
        }
        out.append("\n")
    }
    print(out)
}

input()
solve()

