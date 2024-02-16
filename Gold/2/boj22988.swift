/*
 https://www.acmicpc.net/problem/22988
 22988번 재활용 캠페인
 */
var n: Int = 0
var x: Int = 0
var arr: [Int] = []
func input(){
    let t = readLine()!.split{$0 == " "}.map{Int(String($0))!}
    (n,x) = (t[0],t[1])
    arr = readLine()!.split{$0 == " "}.map{Int(String($0))!}
}
func solve(){
    arr.sort()
    var cnt = 0
    while let t = arr.popLast(){
        if t < x{
            arr.append(t)
            break
        }
        cnt+=1
    }
    var l = 0
    var r = arr.count-1
    
    while l<r{
        if arr[l] * 2 + arr[r] * 2 + x >= 2 * x{
            r -= 1
            cnt += 1
        }
        l += 1
    }
    //r이 결국에는 쌍을 몇 개 만들었는지 알 수 있다.
    //arr.count - (arr.count - 1  - r) * 2 하면 쌍 몇 개 만들었는지 알 수 있음 그걸 전체에서 빼주면 남은 갯수가 나옴
    //2r + 1 - arr.count //남은 갯수
    //r+1 하면 결국은 남은 요소의 갯수가 나옴
    //(r+1) / 3하면 남은 쌍끼리 3개씩 합치면 됨.
    print(cnt + (2 * r + 2 - arr.count) / 3)
}

input()
solve()

