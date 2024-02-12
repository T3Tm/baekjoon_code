/*
 https://www.acmicpc.net/problem/16931
 16931번 겉넓이 구하기
*/
var n: Int?
var m: Int?
var board: [[Int]] = []
func input(){
    let t = readLine()!.split{$0 == " "}.map{Int(String($0))!}
    (n,m) = (t[0],t[1])
    for _ in 0..<n!{
        let temp = readLine()!.split{$0 == " "}.map{Int(String($0))!}
        board.append(temp)
    }
}
func CheckColumn(_ row:Int) -> Int{
    //시작해서 끝가기
    var y: Int = 1
    var ret: Int = board[row][y-1]
    while y<m!{
        if(board[row][y-1] < board[row][y]){
            ret += board[row][y] - board[row][y-1]
        }
        y += 1
    }
    //끝에서 오기
    y -= 2
    ret += board[row][y+1]
    while y>=0{
        if(board[row][y] > board[row][y+1]){
            ret += board[row][y] - board[row][y+1]
        }
        y -= 1
    }
    return ret
}
func CheckRow(_ col:Int) -> Int{
    //시작해서 끝가기
    var x: Int = 1
    var ret: Int = board[x-1][col]
    while x<n!{
        if(board[x][col] > board[x-1][col]){
            ret += board[x][col] - board[x-1][col]
        }
        x += 1
    }
    //끝에서 오기
    x -= 2
    ret += board[x+1][col]
    while x>=0{
        if(board[x][col] > board[x+1][col]){
            ret += board[x][col] - board[x+1][col]
        }
        x -= 1
    }
    return ret
}
func solve(){
    //1. 1열과 1행만 보고 판단
    //2. 하나의 열 또는 행을 보고 한 쪽으로 이동 시 단편 증가, 감소를 판단
    //3. 그럴 때 겉넓이 알아내기
    //4. 겉넓이 에다가 + (n*m)*2 한 뒤에 출력하기
    var res: Int = 0
    for row in 0..<n!{
        res += CheckColumn(row)
    }
    for col in 0..<m!{
        res += CheckRow(col)
    }
    print(res + (n!*m!)*2)
}

input()
solve()

