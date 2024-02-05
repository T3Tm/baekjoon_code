#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1622
    1622번 공통 순열

    알파벳 소문자로 이루어진 두 문자열 a와 b에 대해

    a의 부분 수열의 순열
    b의 부분 수열의 순열
    
    e,p,r,t,t,y

    e,m,n,o,w

    최대한 겹치는 거

    두 문자열에서 최대한 많이 겹치는 거 찾기

*/
using namespace std;
string a,b;
void countAlpha(string &temp,int bit[]){
    for(auto &value:temp){
        bit[value-'a']++;//갯수 세기
    }
}
int main(){
    fast;
    while(getline(cin,a),getline(cin,b)){
        int bit1[26]={0},bit2[26]={0};
        string result;
        countAlpha(a,bit1);
        countAlpha(b,bit2);
        for(int i=0;i<26;i++){
            while(bit1[i] && bit2[i]){
                bit1[i]--;
                bit2[i]--;
                result.push_back(i+'a');
            }
        }
        cout <<result <<endl;
    }
    return 0;
}