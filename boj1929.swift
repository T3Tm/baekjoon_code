import Foundation
let Arr : [Int] = readLine()!.split{$0 == " "}.map{Int(String($0))!}
let (m,n) = (Arr[0],Arr[1])
let SIZE : Int = 1000002
var eratos : [Bool] = Array(repeating: false, count: SIZE)
for i in 2...Int(sqrt(Double(SIZE))){
    if eratos[i] {continue}
    for j in stride(from: i*i, to: SIZE-1, by: i){
        eratos[j] = true
    }
}
eratos[0] = true
eratos[1] = true

for i in m...n{
    if eratos[i]{continue}
    print(i)
}
