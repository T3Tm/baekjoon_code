#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define endl '\n'
/**
    https://www.acmicpc.net/problem/1711
    1711번 직각삼각형
    1. nC3을 한다.
    2. 좌표끼리의 거리를 구한다.
    3. 젤 긴 변을 기준으로 c^2 = a^2 + b^2를 만족하는지 확인한다.

    점과 점 사이의 거리
    a = ((y2-y1)^2+(x2-x1)^2)
    b = //
    c = //

    c^2 = a^2 + b^2


    922경까지 가능함
    9*10^19
    9*10^18
    10^18*8 << 최대

*/
using namespace std;
long long n,answer;
vector<pair<int,int>>loc;
inline long long square(int x){
    return x*x;
}
int main(){
    fast;
    cin >> n;
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        loc.push_back({x,y});
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int z=j+1;z<n;z++){
                long long a=square(loc[i].first-loc[j].first)+square(loc[i].second-loc[j].second);
                long long b=square(loc[j].first-loc[z].first)+square(loc[j].second-loc[z].second);
                long long c=square(loc[z].first-loc[i].first)+square(loc[z].second-loc[i].second);
                if(a==b+c || b==a+c || c==a+b)answer++;
            }
        }
    }
    cout << answer;
    return 0;
}