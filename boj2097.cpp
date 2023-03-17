#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/2097
    2097번 조약돌
    5억개..
    ad-hoc

*/
using namespace std;
int n;
long long result = 4;
int main() {
    fast;
    cin >> n;
    int plus = 2;
    int boundary = 4;
    while (1) {
        if (boundary >= n) {
            break;
        }
        boundary += plus;
        result += 2;
        if (boundary >= n) {//중간에 더해진 거임
            break;
        }
        plus++;//2,3,4 더해질 거임.
        boundary += plus;
        result += 2;
    }
    cout << result;
    return 0;
}