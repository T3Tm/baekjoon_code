/*
 https://www.acmicpc.net/problem/1917
 1917번 정육면체 전개도
 
 
 
 1. 먼저 board에 있는 전개도 탐색
 res = "no"
 for _ in 0..<4{
 if(check(array)){
 yes
 break
 }
 SpinRight()
 }
 print(res)
 1. 남 서 서 서 남
 2. 남 서 남 북 서 서
 3. 남 서 서 남 북 서
 4. 남 동 서 남 북 서 서
 5. 남 남 북 서 서 서
 6. 동 서 남 남 북 서 서
 7. 남 동 서 서 남 북 서
 8. 동 동 서 서 남 서 서
 9. 남 서 서 남 서
 10. 남 동 서 서 남 서
 11. 동 서 남 서 남 서
 0 북 1 동 2 남 3 서

 */
var cube: [[Int]] = [
    [2,3,3,3,2],
    [2,3,2,0,3,3],
    [2,3,3,2,0,3],
    [2,1,3,2,0,3,3],
    [2,2,0,3,3,3],
    [1,3,2,2,0,3,3],
    [2,1,3,3,2,0,3],
    [1,1,3,3,2,3,3],
    [2,3,3,2,3],
    [2,1,3,3,2,3],
    [1,3,2,3,2,3]
]
func SpinRight(_ board:inout [[Int]]) -> Void{
    var temp: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: 6), count: 6)
    //1열이 행으로 가면 된다.
    for j in 0..<6{
        for i in 0..<6{
            temp[j][i] = board[5-i][j]
        }
    }
    board = temp//배열 복사
}
func findTop(_ board:inout [[Int]]) -> (Int, Int){
    for i in 0..<6{
        for j in 0..<6{
            if(board[i][j] == 1){
                return (i,j)
            }
        }
    }
    return (0,0)
}
let dx: [Int] = [-1,0,1,0]
let dy: [Int] = [0,1,0,-1]
func isCude(_ x: Int,_ y: Int,_ board:inout [[Int]]) -> Bool{
    for i in 0..<11{//11개 중에
        var flag: Bool = true
        var nx = x
        var ny = y
        for j in cube[i]{
            nx = nx + dx[j]
            ny = ny + dy[j]
            if nx < 0 || nx >= 6 || ny < 0 || ny >= 6{
                flag = false
                break
            }
            if(board[nx][ny] == 0){
                flag = false
                break
            }
        }
        if flag{return true}
    }
    return false
}
func ReverseLeft(_ board:inout [[Int]]){
    var temp: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: 6), count: 6)
    //마지막열이 첫번째 열으로 가면 된다.
    for i in 0..<6{
        for j in 0..<6{
            temp[i][j] = board[i][5-j]
        }
    }
    board = temp//배열 복사
}
func solve(_ board:inout [[Int]])->Void{
    var res: String = "no"
    for _ in 0..<4{
        let (x,y) = findTop(&board)//상단 찾기
        if isCude(x,y,&board){//해당하는 거 있는지 찾기
            res = "yes"
            break
        }
        SpinRight(&board)//보드 돌리기
    }
    ReverseLeft(&board)
    for _ in 0..<4{
        let (x,y) = findTop(&board)//상단 찾기
        if isCude(x,y,&board){//해당하는 거 있는지 찾기
            res = "yes"
            break
        }
        SpinRight(&board)//보드 돌리기
    }
    print(res)
}
func inputs(_ board:inout [[Int]]) -> Void{
    for _ in 0..<6{
        let temp: [Int] = readLine()!.split{$0 == " "}.map{Int(String($0))!}
        board.append(temp)
    }
}
for _ in 0..<3{
    var board: [[Int]] = []
    inputs(&board)
    solve(&board)
}
