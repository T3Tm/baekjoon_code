#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/10798
    10798번 세로읽기
*/
using namespace std;
int main(){
    fast;
    vector<deque<char>>arr(5);
    for(int i=0;i<5;i++){
        string temp;
        cin >> temp;
        for(int j=0;j<temp.size();j++){
            arr[i].push_back(temp[j]);
        }
    }
    vector<char>result;
    int idx=0;
    while(!arr[0].empty() || !arr[1].empty() ||!arr[2].empty() ||!arr[3].empty() || !arr[4].empty()){
        if(idx==5)idx=0;
        if(arr[idx].size()==0){
            idx++;
            continue;
        }
        result.push_back(arr[idx].front());
        arr[idx].pop_front();
        idx++;
    }
    for(auto &value : result)cout << value;
    return 0;
}