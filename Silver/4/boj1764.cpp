#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1764
    1764번 듣보잡
*/
using namespace std;
int n,m,answer;
map<string,int>words;
int main(){
    fast;
    cin >> n >> m;
    while(n--){
        string temp;
        cin >> temp;
        words[temp]++;
    }
    while(m--){//mlogm
        string temp;
        cin >> temp;
        //logn
        if(words.find(temp)!=words.end()){
            words[temp]--;
            answer++;
        }
    }
    cout << answer << endl;
    for(auto value:words){
        if(value.second==0){
            cout << value.first << endl;
        }
    }
    return 0;
}