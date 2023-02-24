#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/25206
    25206번 너의 평점은
*/
using namespace std;
map<string,double>convert={{"A+",4.5},{"A0",4.0},{"B+",3.5},{"B0",3.0},{"C+",2.5},
                            {"C0",2.0},{"D+",1.5},{"D0",1.0},{"F",0.0}};
int main(){
    fast;
    double sum=0,t=0;
    for(int i=0;i<20;i++){
        string a,c;
        double b;
        cin >> a >> b >> c;
        if(c[0]=='P')continue;
        t+=b;
        sum+=convert[c]*b;
    }
    cout.precision(7);
    cout << sum/t;
    return 0;
}