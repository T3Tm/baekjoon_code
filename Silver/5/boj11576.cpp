#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
   https://www.acmicpc.net/problem/11576
   11576번 Base Conversion
*/
using namespace std;
int number, a, b, c;
inline long long invol(int value, int c) {
    long long temp = 1;
    for (int i = 0; i < c; i++)temp *= value;
    return temp;
}
void getNumber(string& src) {
    int mul = c - 1;//몇 번째 비트자리.
    string num;
    for (auto& value : src) {
        if (value == ' ') {
            int bitNum = stoi(num);
            number += (bitNum * invol(a, mul--));
            num.clear();
        }
        else {
            num.push_back(value);
        }
    }
    if (!num.empty()) {
        int bitNum = stoi(num);
        number += (bitNum * invol(a, mul--));
    }
}
void jinbub(int num) {
    if (num < b)cout << num << " ";
    else {
        jinbub(num / b);
        cout << num % b << " ";
    }
}
int main() {
    fast;
    string src;
    cin >> a >> b >> c;
    cin.ignore();
    getline(cin, src);
    getNumber(src);
    jinbub(number);
    return 0;
}
