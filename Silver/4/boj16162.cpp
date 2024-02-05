#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/16162
    16162번 가희와 3단 고음

    Dp문제
*/
using namespace std;
int n,a,d,result;
bool flag=false;
int main(){
    fast;
    cin >> n >> a >> d;
    while(n--){
        int number;
        cin >> number;
        if(number==a){
            result++;
            a+=d;
        }
    }
    cout << result;
    return 0;
}