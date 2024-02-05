import Foundation
final class FileIO {
    private let buffer:[UInt8]
    private var index: Int = 0

    init(fileHandle: FileHandle = FileHandle.standardInput) {

        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)] // 인덱스 범위 넘어가는 것 방지
    }

    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }

        return buffer[index]
    }

    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true

        while now == 10
                || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }

        return sum * (isPositive ? 1:-1)
    }

    @inline(__always) func readString() -> String {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }

    @inline(__always) func readByteSequenceWithoutSpaceAndLineFeed() -> [UInt8] {
        var now = read()

        while now == 10 || now == 32 { now = read() } // 공백과 줄바꿈 무시

        let beginIndex = index-1

        while now != 10,
              now != 32,
              now != 0 { now = read() }

        return Array(buffer[beginIndex..<(index-1)])
    }
}
//유파 좌표압축 기술을 이용하면 쉽게 풀 것 같다.
//union, find,
func find(x: Int, parent :inout [Int])-> Int{
  if parent[x] == -1 {return x} //부모가 -1이면 자신을 리턴
  parent[x] = find(x: parent[x],parent: &parent)
  return parent[x]
}
func union(a: Int, b: Int,parent: inout [Int]){
  let A:Int = find(x: a,parent: &parent)
  let B:Int = find(x: b,parent: &parent)
  if A > B{//더 큰 아이가 작은 
    parent[A] = B
  }else{
    parent[B] = A
  }
}

let fio = FileIO()

let n = fio.readInt()
let m = fio.readInt()
var parent: [Int] = [Int](repeating: -1, count: n+2)
var res: Int = 0
for Number in 1...m{
  let x = fio.readInt()
  let y = fio.readInt()
  if find(x: x,parent: &parent) == find(x: y,parent: &parent){//둘이 부모가 같니?
    res = Number
    break
  }else{
    union(a: x,b: y,parent:&parent)
  }
}
print(res)