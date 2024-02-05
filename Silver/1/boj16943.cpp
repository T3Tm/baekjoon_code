#include <bits/stdc++.h>
#define endl "\n"
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
/*
        https://www.acmicpc.net/problem/16943
        숫자 재배치
        -	c는 0으로 시작 안 된다.
        -	b보다 작으면서 가장 큰 값을 찾자.
        10^9 => 10억
*/
using namespace std;
int a, b, result = -1;
vector<int> numb;
int main() {
    fast;
    cin >> a >> b;
    while (a) {
        numb.push_back(a % 10);
        a /= 10;
    }
    sort(numb.begin(), numb.end());
    do {
        if (numb[0] == 0) continue;
        int c = 0;
        for (auto value : numb) {  // 숫자 뽑아내기
            c = c * 10 + value;
        }
        if (b > c) {
            result = max(c, result);
        }
    } while (next_permutation(numb.begin(), numb.end()));
    cout << result;
    return 0;
}