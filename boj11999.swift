import Foundation
let Arr : [Int] = readLine()!.split{$0 == " "}.map{Int(String($0))!}
let (x,y,m) = (Arr[0],Arr[1],Arr[2])
var res : Int = 0
for a in 0...1000{
    for b in 0...1000{
        if a*x + b*y <= m{res = max(res,a*x + b*y)}
    }
}
print(res)