#include <bits/stdc++.h>

using namespace std;
struct truck{
    int s,e,v;
};
int main(){
    int n,c; cin >> n >> c;

    int m;cin >> m;
    vector<truck>query(m);
    for(auto &[s,e,v]:query)cin >> s >> e >> v;

    sort(query.begin(),query.end(),[](const truck& f, const truck& b){
       if(f.e == b.e)return f.s < b.s;
        return f.e < b.e;
    });

    int village[2002]{};
    int result{};
    for(auto &[s,e,v]: query){
        int plus{};
        for(int i{s};i<e;i++){
            plus = max(plus, village[i]);
        }
        plus = min(c - plus, min(v, c));
        result += plus;
        for(int i{s};i<e;i++){
            village[i] += plus;
        }
    }
    cout << result;
    return 0;
}