#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/11478
    11478번 서로 다른 부분 문자열의 개수
    알파벳 26개 이고 최대 들어갈 수 있다.
    최대 경우의 수 500500이다.

*/
using namespace std;
set<string>Substring;
int main(){
    fast;
    string S;
    cin >> S;
    int S_len=S.size();
    for(int i=1;i<=S_len;i++){//1000
        int idx=0;
        while(idx+(i-1) < S_len){//1000
            Substring.insert(S.substr(idx,i));//1000
            idx++;
        }
    }
    cout << Substring.size();
    return 0;
}