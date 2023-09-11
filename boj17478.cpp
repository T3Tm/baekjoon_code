#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0)
#define endl '\n' 
/*
    https://www.acmicpc.net/problem/17478
    17478번 재귀함수가 무엇인가요?
    
*/
            
using namespace std;
int n;
void coutdash(int count){
    string a;a.append(count*4,'_');
    cout << a;
}
void whatIsrecursion(int depth=0){
    coutdash(depth);
    cout << "\"재귀함수가 뭔가요?\"" <<endl;
    if(depth==n){
        coutdash(depth);
        cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"" << endl;
        coutdash(depth);
        cout << "라고 답변하였지." <<endl;
        return;
    }
    coutdash(depth);
    cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어." << endl;
    coutdash(depth);
    cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지." << endl;
    coutdash(depth);
    cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"" << endl;
    whatIsrecursion(depth+1);
    coutdash(depth);
    cout << "라고 답변하였지." << endl;
}
int main(){
    fast;cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<endl;
    whatIsrecursion();
}