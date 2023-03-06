#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
 * https://www.acmicpc.net/problem/12764
 * 12764번 싸지방에 간 준하
 * 모든 사람은 싸지방에 들어왔을 때 비어있는 자리 중에서 번호가 가장 작은 자리에 앉는 것이 규칙이다.
 *  모든 사람이 기다리지 않고 싸지방을 이용할 수 있는 컴퓨터의 최소 개수와 자리별로 몇 명의 사람이 사용했는가를 구하시오.
 * 
*/
using namespace std;
int n,result;
priority_queue<pair<int,int>>junha;//종료,좌석
priority_queue<int>NumberIdx;
vector<pair<int,int>>arr;
int bits[100002];
int main(){
    fast;
    cin >> n;
    while(n--){
        int p,q;
        cin >> p >> q;
        arr.push_back({p,q});
    }
    sort(arr.begin(),arr.end());//순서 정렬
    for(int i=0;i<arr.size();i++){
        auto value=arr[i];
        int p=value.first,q=value.second;//시작, 끝
        int idx;
        while(!junha.empty() && -junha.top().first < p){
            NumberIdx.push(-junha.top().second);
            junha.pop();
        }
        if(NumberIdx.empty())idx=junha.size()+1;
        else{
            idx=-NumberIdx.top();NumberIdx.pop();
        } 
        junha.push({-q,idx});//종료
        bits[idx]++;
        result=max(result,(int)junha.size());
    }
    cout << result << endl;
    for(int i=1;i<=result;i++){
        cout << bits[i] << ' ';
    }
    return 0;

}