#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1487
    1487번 물건 팔기
    10^6 작거나 같은 음이 아닌 정수, 배송비는 0이 될 수도 있다.?
    버그 문제 계속 segment 에러뜸
*/
using namespace std;
int n;
int result=0;
int sellmax=0;
vector<pair<int,int>>arr;
int main(){
    fast;
    cin >> n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        int total=0;
        for(int j=i;j<n;j++){//arr[i]의 가격으로 판다면?
            int value=arr[i].first - arr[j].second;
            if( value > 0 )total+=value;
        }
        if(sellmax< total){
            sellmax = total;
            result=arr[i].first;
        }
    }
    cout << result;
    return 0;
}