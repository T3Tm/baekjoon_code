#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/4134
    4134번 다음 소수
*/
using namespace std;
bool prime(long long n) {
    if (n == 1 || n == 0) return false;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
long long n;
int main() {
    fast;
    cin >> n;
    while (n--) {
        long long number;
        cin >> number;
        while(1){
            if(prime(number)){
                cout << number << endl;
                break;
            }
            number++;
        }
    }
    return 0;
}