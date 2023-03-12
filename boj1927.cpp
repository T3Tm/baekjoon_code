#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1927
    1927번
    
    1. 자연수 x를 넣는다.
    2. 배열에서 가장 작은 값을 출력하고 배열에서 제거한다.
*/
using namespace std;
int n,number;
priority_queue<int>minheap;
int main(){
    fast;
    cin >> n;
    while(n--){
        cin >> number;
        if(number){
            minheap.push(-number);
        }else{
            if(minheap.empty())cout << 0 << endl;
            else{
                cout << -minheap.top() << endl;
                minheap.pop();
            }
        }
    }
    return 0;
}